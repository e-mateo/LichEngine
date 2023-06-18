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

const float PI = 3.14159265359;
uniform float far_plane;
uniform vec3 camPos;
uniform sampler2D gPosition;
uniform sampler2D gNormal;
uniform sampler2D gAlbedo;
uniform sampler2D ssaoText;
uniform sampler2D metalRoughAOBloom;

float DistributionGGX(vec3 N, vec3 H, float roughness);
float GeometrySchlickGGX(float NdotV, float roughness);
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness);
vec3 fresnelSchlick(float cosTheta, vec3 F0);

struct DirLight {
    vec3 direction;
    vec3 diffuse;
    bool shadow;
    mat4 lightSpaceMatrix;
    float ambient;
};  
#define NR_DIR_LIGHTS 4
uniform DirLight dirLights[NR_DIR_LIGHTS];

struct PointLight {    
    vec3 position;
    vec3 diffuse;
    float constant;
    float linear;
    float quadratic;  
    bool shadow;
    float ambient;
};  
#define NR_POINTS_LIGHTS 10
uniform PointLight pointLights[NR_POINTS_LIGHTS];

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cosInerAngle;
    float cosOuterAngle;
    vec3 diffuse;
    bool shadow;
    mat4 lightSpaceMatrix;
    float ambient;
};
#define NR_SPOTS_LIGHTS 4
uniform SpotLight spotLights[NR_SPOTS_LIGHTS];

uniform int nbDirLights;
uniform int nbPointLights;
uniform int nbSpotLights;

#define NR_DIR_SHADOWS 4
#define NR_SPOTS_SHADOWS 4
#define NR_POINTS_SHADOWS 7

uniform sampler2D shadowDirMaps[NR_DIR_SHADOWS];
uniform sampler2D shadowSpotMaps[NR_SPOTS_SHADOWS];
uniform samplerCube shadowCubeMaps[NR_POINTS_SHADOWS];

vec3 PBRPointLight(vec3 FragPos, vec3 Normal, float Metallic, float Roughness, vec3 Albedo, vec3 V, vec3 F0, PointLight pointLight, int index, int indexShadow);
vec3 PBRDirLight(vec3 FragPos, vec3 Normal, float Metallic, float Roughness, vec3 Albedo, vec3 V, vec3 F0, DirLight dirLight, int index, int indexShadow);
vec3 PBRSpotLight(vec3 FragPos, vec3 Normal, float Metallic, float Roughness, vec3 Albedo, vec3 V, vec3 F0, SpotLight spotLight, int index, int indexShadow);

float ShadowCalculationPointLight(vec3 fragPos, vec3 lightPos, int index);
float ShadowDirLightCalculation(vec4 fragPosLightSpace, vec3 normal, vec3 lightDir, int index);
float ShadowSpotLightCalculation(vec4 fragPosLightSpace, vec3 normal, vec3 lightDir, int index);


void main()
{             
    // retrieve data from gbuffer
    vec3 FragPos = texture(gPosition, TexCoord).rgb;
    vec3 Normal = texture(gNormal, TexCoord).rgb;
    vec3 Albedo = texture(gAlbedo, TexCoord).rgb;
    float Metallic = texture(metalRoughAOBloom, TexCoord).r;
    float Roughness = texture(metalRoughAOBloom, TexCoord).g;
    float AmbientOcclusion = texture(metalRoughAOBloom, TexCoord).b * texture(ssaoText, TexCoord).r;
    float bloom = texture(metalRoughAOBloom, TexCoord).a;
    vec3 V = normalize(camPos - FragPos);

    vec3 F0 = vec3(0.04); 
    F0 = mix(F0, Albedo, Metallic);

    vec3 Lo = vec3(0.0);

    int indexShadowPoint = 0;
    int indexShadowDir = 0;
    int indexShadowSpot = 0;
    float ambient = 0;

    for(int i = 0; i < nbPointLights; i++) 
    {
        vec3 light = PBRPointLight(FragPos, Normal, Metallic, Roughness, Albedo, V, F0, pointLights[i], i, indexShadowPoint);
        Lo += light;
        if(pointLights[i].shadow)
            indexShadowPoint++;

        ambient += pointLights[i].ambient;
    }

    for(int i = 0; i < nbDirLights; i++) 
    {
        vec3 light = PBRDirLight(FragPos, Normal, Metallic, Roughness, Albedo, V, F0, dirLights[i], i, indexShadowDir);
        Lo += light;
        if(dirLights[i].shadow)
            indexShadowDir++;

        ambient += dirLights[i].ambient;
    }

    for(int i = 0; i < nbSpotLights; i++) 
    {
        vec3 light = PBRSpotLight(FragPos, Normal, Metallic, Roughness, Albedo, V, F0, spotLights[i], i, indexShadowSpot);
        Lo += light;
        if(spotLights[i].shadow)
            indexShadowSpot++;

        ambient += spotLights[i].ambient;
    }

    vec3 ambientColor = vec3(ambient) * Albedo * AmbientOcclusion;
    vec3 color = ambientColor + Lo; 

    FragColor = vec4(color, 1.f);

    float brightness = dot(FragColor.rgb, vec3(0.2126, 0.7152, 0.0722));


    if(brightness > 1.0 && bloom >= 1.0)
        BrightColor = vec4(FragColor.rgb, 1.0);
    else
        BrightColor = vec4(0.0, 0.0, 0.0, 1.0);
}


// Light

vec3 PBRPointLight(vec3 FragPos, vec3 Normal, float Metallic, float Roughness, vec3 Albedo, vec3 V, vec3 F0, PointLight pointLight, int index, int indexShadow)
{
        vec3 L = normalize(pointLight.position - FragPos);
        vec3 H = normalize(V + L);
  
        //float distance = length(pointLight.position - FragPos);
        //float attenuation = 1.0 / (distance * distance);
        float dist = length(pointLight.position - FragPos);
        float attenuation = 1.0 / (pointLight.constant + pointLight.linear * dist + pointLight.quadratic * (dist * dist));    
        vec3 radiance = pointLight.diffuse * attenuation; 

        float NDF = DistributionGGX(Normal, H, Roughness);       
        float G = GeometrySmith(Normal, V, L, Roughness);  
        vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

        vec3 numerator = NDF * G * F;
        float denominator = 4.0 * max(dot(Normal, V), 0.0) * max(dot(Normal, L), 0.0)  + 0.0001;
        vec3 specular = numerator / denominator;  

        vec3 kS = F;
        vec3 kD = vec3(1.0) - kS;
        kD *= 1.0 - Metallic;	
  
        float NdotL = max(dot(Normal, L), 0.0);        

        float shadow = 0.f;
        if(pointLight.shadow)
        {
            shadow = ShadowCalculationPointLight(FragPos, pointLight.position, indexShadow);
        }

        return (1.0 - shadow) * ((kD * Albedo / PI + specular) * radiance * NdotL);

}

vec3 PBRDirLight(vec3 FragPos, vec3 Normal, float Metallic, float Roughness, vec3 Albedo, vec3 V, vec3 F0, DirLight dirLight, int index, int indexShadow)
{
        vec3 L = normalize(-dirLight.direction);
        vec3 H = normalize(V + L);
  
        vec3 radiance = dirLight.diffuse; 

        float NDF = DistributionGGX(Normal, H, Roughness);       
        float G = GeometrySmith(Normal, V, L, Roughness);  
        vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

        vec3 numerator = NDF * G * F;
        float denominator = 4.0 * max(dot(Normal, V), 0.0) * max(dot(Normal, L), 0.0)  + 0.0001;
        vec3 specular = numerator / denominator;  

        vec3 kS = F;
        vec3 kD = vec3(1.0) - kS;
        kD *= 1.0 - Metallic;	
  
        float NdotL = max(dot(Normal, L), 0.0);        

        float shadow = 0.f;
        if(dirLight.shadow)
        {
            vec4 FragPosLightSpace = dirLight.lightSpaceMatrix * vec4(FragPos, 1.0);
            shadow = ShadowDirLightCalculation(FragPosLightSpace, Normal, L, indexShadow);
        }

        return (1.0 - shadow) * ((kD * Albedo / PI + specular) * radiance * NdotL);
}

vec3 PBRSpotLight(vec3 FragPos, vec3 Normal, float Metallic, float Roughness, vec3 Albedo, vec3 V, vec3 F0, SpotLight spotLight, int index, int indexShadow)
{
        vec3 L = normalize(spotLight.position - FragPos);
        vec3 H = normalize(V + L);
  
        vec3 fragToLight = normalize(spotLight.position - FragPos);
        float cosTheta = dot(fragToLight, normalize(-spotLight.direction));
        float epsilon = spotLight.cosInerAngle - spotLight.cosOuterAngle;
        float attenuation = clamp((cosTheta - spotLight.cosOuterAngle) / epsilon, 0.0, 1.0);
        vec3 radiance = spotLight.diffuse * attenuation; 

        float NDF = DistributionGGX(Normal, H, Roughness);       
        float G = GeometrySmith(Normal, V, L, Roughness);  
        vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

        vec3 numerator = NDF * G * F;
        float denominator = 4.0 * max(dot(Normal, V), 0.0) * max(dot(Normal, L), 0.0)  + 0.0001;
        vec3 specular = numerator / denominator;  

        vec3 kS = F;
        vec3 kD = vec3(1.0) - kS;
        kD *= 1.0 - Metallic;	
  
        float NdotL = max(dot(Normal, L), 0.0);        

        float shadow = 0.f;
        if(spotLight.shadow)
        {
            vec4 FragPosLightSpace = spotLight.lightSpaceMatrix * vec4(FragPos, 1.0);
            shadow = ShadowSpotLightCalculation(FragPosLightSpace, Normal, L, indexShadow);
        }

        return (1.0 - shadow) * ((kD * Albedo / PI + specular) * radiance * NdotL);
}


//PBR equation

float DistributionGGX(vec3 N, vec3 H, float roughness)
{
    float a = roughness * roughness;
    float a2 = a * a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH * NdotH;
	
    float num = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;
	
    return num / denom;
}

float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float num = NdotV;
    float denom = NdotV * (1.0 - k) + k;
	
    return num / denom;
}

float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);
	
    return ggx1 * ggx2;
}

vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}  

// Shadow

vec3 gridSamplingDisk[20] = vec3[]
(
   vec3( 1,  1,  1), vec3( 1, -1,  1), vec3(-1, -1,  1), vec3(-1,  1,  1), 
   vec3( 1,  1, -1), vec3( 1, -1, -1), vec3(-1, -1, -1), vec3(-1,  1, -1),
   vec3( 1,  1,  0), vec3( 1, -1,  0), vec3(-1, -1,  0), vec3(-1,  1,  0),
   vec3( 1,  0,  1), vec3(-1,  0,  1), vec3( 1,  0, -1), vec3(-1,  0, -1),
   vec3( 0,  1,  1), vec3( 0, -1,  1), vec3( 0, -1, -1), vec3( 0,  1, -1)
); 

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
