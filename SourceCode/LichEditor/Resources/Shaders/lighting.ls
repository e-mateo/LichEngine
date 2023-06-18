##vert##
#version 450 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

void main()
{
    TexCoord = aTexCoord;
    gl_Position = vec4(aPos, 1.0);
}



##frag##
#version 450 core
layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

in vec2 TexCoord;

uniform int nbDirLights;
uniform int nbPointLights;
uniform int nbSpotLights;

uniform vec3 camPos;
uniform float near_plane;
uniform float far_plane;

uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedoSpec;
uniform sampler2D ssao;


struct DirLight {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    bool shadow;

    mat4 lightSpaceMatrix;
};  

#define NR_DIR_LIGHTS 4
uniform DirLight dirLights[NR_DIR_LIGHTS];
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir, vec4 fragPosLightSpace, float AmbientOcclusion, int index); 
float ShadowDirLightCalculation(vec4 fragPosLightSpace, vec3 normal, vec3 lightDir, int index);


struct PointLight {    
    vec3 position;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;  

    bool shadow;
};  
#define NR_POINTS_LIGHTS 4
uniform PointLight pointLights[NR_POINTS_LIGHTS];
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, float AmbientOcclusion, int index);
float ShadowCalculationPointLight(vec3 fragPos, vec3 lightPos, int index);


struct SpotLight {
    vec3 position;
    vec3 direction;
    float cosInerAngle;
    float cosOuterAngle;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    bool shadow;

    mat4 lightSpaceMatrix;
};
#define NR_SPOTS_LIGHTS 4
uniform SpotLight spotLights[NR_SPOTS_LIGHTS];
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec4 fragPosLightSpace, float AmbientOcclusion, int index);
float ShadowSpotLightCalculation(vec4 fragPosLightSpace, vec3 normal, vec3 lightDir, int index);

uniform sampler2D shadowDirMaps[NR_DIR_LIGHTS];
uniform sampler2D shadowSpotMaps[NR_SPOTS_LIGHTS];
uniform samplerCube shadowCubeMaps[NR_POINTS_LIGHTS];

vec3 gridSamplingDisk[20] = vec3[]
(
   vec3( 1,  1,  1), vec3( 1, -1,  1), vec3(-1, -1,  1), vec3(-1,  1,  1), 
   vec3( 1,  1, -1), vec3( 1, -1, -1), vec3(-1, -1, -1), vec3(-1,  1, -1),
   vec3( 1,  1,  0), vec3( 1, -1,  0), vec3(-1, -1,  0), vec3(-1,  1,  0),
   vec3( 1,  0,  1), vec3(-1,  0,  1), vec3( 1,  0, -1), vec3(-1,  0, -1),
   vec3( 0,  1,  1), vec3( 0, -1,  1), vec3( 0, -1, -1), vec3( 0,  1, -1)
);   

void main()
{             
    // retrieve data from gbuffer
    vec3 FragPos = texture(gPosition, TexCoord).rgb;
    vec3 Normal = texture(gNormal, TexCoord).rgb;
    vec3 Diffuse = texture(gAlbedoSpec, TexCoord).rgb;
    float Specular = texture(gAlbedoSpec, TexCoord).a;
    float AmbientOcclusion = texture(ssao, TexCoord).r;

    vec3 colorLightDir = vec3(0,0,0);
    vec3 colorLightPoint = vec3(0,0,0);
    vec3 colorLightSpot = vec3(0,0,0);

    vec3 view = normalize(camPos - FragPos);

    for(int i = 0; i < nbDirLights; i++)
    {
        vec4 FragPosLightSpace = dirLights[i].lightSpaceMatrix * vec4(FragPos, 1.0);
        colorLightDir += CalcDirLight(dirLights[i], Normal, view, FragPosLightSpace, AmbientOcclusion, i);
    }

    for(int i = 0; i < nbPointLights; i++)
        colorLightPoint += CalcPointLight(pointLights[i], Normal, FragPos, view, AmbientOcclusion, i);

    for(int i = 0; i < nbSpotLights; i++)
    {
        vec4 FragPosLightSpace = spotLights[i].lightSpaceMatrix * vec4(FragPos, 1.0);
        colorLightSpot += CalcSpotLight(spotLights[i], Normal, FragPos, view, FragPosLightSpace, AmbientOcclusion, i);
    }

    vec3 colorLight = colorLightDir + colorLightPoint + colorLightSpot;

    vec3 color = Diffuse * colorLight;
    FragColor = vec4(color, 1.0);

    float brightness = dot(FragColor.rgb, vec3(0.2126, 0.7152, 0.0722));
    if(brightness > 1.0)
        BrightColor = vec4(FragColor.rgb, 1.0);
    else
        BrightColor = vec4(0.0, 0.0, 0.0, 1.0);
}


vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir, vec4 fragPosLightSpace, float AmbientOcclusion, int index)
{
    vec3 lightDir = normalize(-light.direction);
    vec3 halfwayDir = normalize(lightDir + viewDir);  
 
    vec3 ambient = light.ambient * AmbientOcclusion;

    float Id = max(dot(lightDir,normal), 0.0);
    vec3 diffuse  = light.diffuse  * Id;

    float Is = pow(max(dot(halfwayDir, normal), 0.0), 256);
    vec3 specular = light.specular * Is;


    if(light.shadow)
    {
        float shadow = ShadowDirLightCalculation(fragPosLightSpace, normal, lightDir, index);       
        return (ambient + (1.0 - shadow) * (diffuse + specular));
    }

    return (ambient + diffuse + specular);
}

float ShadowDirLightCalculation(vec4 fragPosLightSpace, vec3 normal, vec3 lightDir, int index)
{
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5; 
    float closestDepth = texture(shadowDirMaps[index], projCoords.xy).r; 
    float currentDepth = projCoords.z; 
    float bias = max(0.001 * (1.0 - dot(normal, lightDir)), 0.001); 

    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowDirMaps[index], 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadowDirMaps[index], projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
        }    
    }
    shadow /= 9.0;
    
    if(projCoords.z > 1.0)
        shadow = 0.0;

    return shadow;
}


vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, float AmbientOcclusion, int index)
{
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);  

    vec3 ambient = light.ambient * AmbientOcclusion;

    float Id = max(dot(lightDir,normal), 0.0);
    vec3 diffuse = light.diffuse * Id;

    float Is =  pow(max(dot(halfwayDir, normal), 0.0), 256);
    vec3 specular = light.specular * Is;

    float dist = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * dist + light.quadratic * (dist * dist));    

    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;

    if(light.shadow)
    {
        float shadow = ShadowCalculationPointLight(fragPos, light.position, index);                      
        return (ambient + (1.0 - shadow) * (diffuse + specular));
    }

    return (ambient + diffuse + specular);

} 

float ShadowCalculationPointLight(vec3 fragPos, vec3 lightPos, int index)
{
    vec3 fragToLight = fragPos - lightPos;
    float currentDepth = length(fragToLight);

    float shadow = 0.0;
    float bias = 0.015;
    int samples = 20;
    float viewDistance = length(camPos - fragPos);
    float diskRadius = (1.0 + (viewDistance / far_plane)) / 25.0;
    for(int i = 0; i < samples; ++i)
    {
        float closestDepth = texture(shadowCubeMaps[index], fragToLight + gridSamplingDisk[i] * diskRadius).r;
        closestDepth *= far_plane;
        if(currentDepth - bias > closestDepth)
            shadow += 1.0;
    }
    shadow /= float(samples);

    return shadow;
}  


vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec4 fragPosLightSpace, float AmbientOcclusion, int index)
{
    vec3 fragToLight = normalize(light.position - fragPos);
    float cosTheta = dot(fragToLight, normalize(-light.direction));    //cosinus of the angle between the direction vector and the fragToLight vector (should be higher than light.cosAngle)
    float epsilon = light.cosInerAngle - light.cosOuterAngle;
    float intensity = clamp((cosTheta - light.cosOuterAngle) / epsilon, 0.0, 1.0);

    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir); 

    vec3 ambient = light.ambient * AmbientOcclusion;

    float Id = max(dot(lightDir,normal), 0.0);
    vec3 diffuse = light.diffuse * Id;

    float Ia =  pow(max(dot(halfwayDir, normal), 0.0), 256);
    vec3 specular = light.specular * Ia;

    diffuse  *= intensity;
    specular *= intensity;

    if(light.shadow)
    {
        float shadow = ShadowSpotLightCalculation(fragPosLightSpace, normal, normalize(-light.direction), index);       
        return (ambient + (1.0 - shadow) * (diffuse + specular));
    }

    return (ambient + diffuse + specular);

}

float ShadowSpotLightCalculation(vec4 fragPosLightSpace, vec3 normal, vec3 lightDir, int index)
{
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5; 
    float closestDepth = texture(shadowSpotMaps[index], projCoords.xy).r; 
    float currentDepth = projCoords.z; 
    float bias = max(0.01 * (1.0 - dot(normal, lightDir)), 0.001); 

    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowSpotMaps[index], 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadowSpotMaps[index], projCoords.xy + vec2(x, y) * texelSize).r; 
            shadow += currentDepth - bias > pcfDepth  ? 1.0 : 0.0;        
        }    
    }
    shadow /= 9.0;
    
    if(projCoords.z > 1.0)
        shadow = 0.0;

    return shadow;
}