#version 450 core
##vert##
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;
layout(location = 3) in vec3 aTangent;
layout(location = 4) in vec3 aBiTangent;

uniform mat4 model;
uniform mat4 mvp;

out vec4 FragPos;
out vec3 Normal;
out vec2 TexCoord;

void main()
{
	gl_Position = mvp * vec4(aPos, 1.0);
	FragPos = model * vec4(aPos, 1.0);
	Normal = mat3(transpose(inverse(model))) * aNormal;
	TexCoord = aTexCoord;
}



##frag##
#version 450 core
out vec4 FragColor;

in vec4 FragPos;
in vec3 Normal;
in vec2 TexCoord;

uniform sampler2D text;

uniform vec3 camPos;
uniform int nbDirLights;
uniform int nbPointsLights;
uniform int nbSpotsLights;


struct DirLight {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  
#define NR_DIR_LIGHTS 4
uniform DirLight dirLights[NR_DIR_LIGHTS];
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir); 

struct PointLight {    
    vec3 position;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;  
};  
#define NR_POINTS_LIGHTS 4
uniform PointLight pointLights[NR_POINTS_LIGHTS];
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cosInerAngle;
    float cosOuterAngle;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
#define NR_POINTS_LIGHTS 4
uniform SpotLight spotLights[NR_POINTS_LIGHTS];
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);


void main()
{
    vec3 colorLight = vec3(0,0,0);
    vec3 norm = normalize(Normal);
    vec3 fragPos = vec3(FragPos);
    vec3 view = normalize(camPos - fragPos);

    for(int i = 0; i < nbDirLights; i++)
        colorLight += CalcDirLight(dirLights[i],norm,view);

    for(int i = 0; i < nbPointsLights; i++)
        colorLight += CalcPointLight(pointLights[i],norm,fragPos,view);

    for(int i = 0; i < nbSpotsLights; i++)
        colorLight += CalcSpotLight(spotLights[i],norm,fragPos,view);

    FragColor = texture(text, TexCoord);
	FragColor = FragColor * vec4(colorLight,1);
};

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    vec3 halfwayDir = normalize(lightDir + viewDir);  
 
    vec3 ambient = light.ambient;

    float Id = max(dot(lightDir,normal), 0.0);
    vec3 diffuse  = light.diffuse  * Id;

    float Is = pow(max(dot(halfwayDir, normal), 0.0), 256);
    vec3 specular = light.specular * Is;

    return (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);  

    vec3 ambient = light.ambient;

    float Id = max(dot(lightDir,normal), 0.0);
    vec3 diffuse = light.diffuse * Id;

    float Is =  pow(max(dot(halfwayDir, normal), 0.0), 256);
    vec3 specular = light.specular * Is;

    float dist = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * dist + light.quadratic * (dist * dist));    

    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
} 

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 fragToLight = normalize(light.position - fragPos);
    float cosTheta = dot(fragToLight, normalize(-light.direction));    //cosinus of the angle between the direction vector and the fragToLight vector (should be higher than light.cosAngle)
    float epsilon = light.cosInerAngle - light.cosOuterAngle;
    float intensity = clamp((cosTheta - light.cosOuterAngle) / epsilon, 0.0, 1.0);

    vec3 lightDir = normalize(light.position - fragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir); 

    vec3 ambient = light.ambient;

    float Id = max(dot(lightDir,normal), 0.0);
    vec3 diffuse = light.diffuse * Id;

    float Ia =  pow(max(dot(halfwayDir, normal), 0.0), 256);
    vec3 specular = light.specular * Ia;

    diffuse  *= intensity;
    specular *= intensity;

    return (ambient + diffuse + specular);
}