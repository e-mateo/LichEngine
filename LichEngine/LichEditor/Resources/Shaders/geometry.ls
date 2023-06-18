##vert##
#version 450 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;
layout(location = 3) in vec3 aTangent;
layout(location = 4) in vec3 aBiTangent;
layout(location = 5) in ivec4 boneIndices;
layout(location = 6) in vec4 boneWeights;

uniform mat4 model;
uniform mat4 viewMatrix;
uniform mat4 mvp;
uniform mat4 boneMatrices[200];
uniform bool isAnimated;

out vec3 FragPos;
out vec3 FragPosView;
out vec3 Normal;
out vec3 ViewNormal;
out vec2 TexCoord;
out mat3 TBN;
out vec3 TangentViewPos;
out vec3 TangentFragPos;

uniform vec3 viewPos;

void main()
{
    vec3 T = normalize(mat3(model) * aTangent);
    vec3 B = normalize(mat3(model) * aBiTangent);
    vec3 N = normalize(mat3(model) * aNormal);
    TBN = mat3(T, B, N);

    if (isAnimated)
    {
        vec4 pos = vec4(0,0,0,0);
        vec3 localNormal = vec3(0,0,0);

        for (int i = 0; i < 4; i++)
        {
            if (int(boneIndices[i]) == -1)
                continue;

            pos += (boneMatrices[int(boneIndices[i])] * vec4(aPos, 1.f)) * boneWeights[i];
            localNormal += (mat3(boneMatrices[int(boneIndices[i])]) * aNormal) * boneWeights[i];
        }
        gl_Position = mvp * vec4(pos.xyz, 1.0);
        FragPos = (model * vec4(pos.xyz, 1.0)).xyz;
        FragPosView = (viewMatrix * model * vec4(pos.xyz, 1.0)).xyz;
        Normal = transpose(inverse(mat3(model))) * localNormal;
        ViewNormal = transpose(inverse(mat3(viewMatrix * model))) * localNormal;
    }
    else
    { 
        gl_Position = mvp * vec4(aPos, 1.0);
        FragPos = (model * vec4(aPos, 1.0)).xyz;
        FragPosView = (viewMatrix * model * vec4(aPos, 1.0)).xyz;
        Normal = transpose(inverse(mat3(model))) * aNormal;
        ViewNormal = transpose(inverse(mat3(viewMatrix * model))) * aNormal;
    }

    TexCoord = aTexCoord;
    TangentViewPos  = TBN * viewPos;
    TangentFragPos  = TBN * FragPos;
}



##frag##
#version 450 core
layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gViewPosition;
layout (location = 2) out vec3 gNormal;
layout (location = 3) out vec3 gViewNormal;
layout (location = 4) out vec4 gAlbedo;
layout (location = 5) out vec4 gMetalRoughAOBloom;

in vec3 FragPos;
in vec3 FragPosView;
in vec3 Normal;
in vec3 ViewNormal;
in vec2 TexCoord;
in mat3 TBN;
in vec3 TangentViewPos;
in vec3 TangentFragPos;

uniform sampler2D text_diffuse;
uniform sampler2D normal_map;
uniform sampler2D height_map;
uniform sampler2D metallic_map;
uniform sampler2D roughness_map;
uniform sampler2D ao_map;

uniform bool handleDiffuse;
uniform bool handleNormal;
uniform bool handleParallax;
uniform bool handleMetallic;
uniform bool handleRoughness;
uniform bool handleAO;

uniform float height_scale;
uniform float metallic;
uniform float roughness;
uniform float opacity;
uniform vec4 albedo;
uniform bool bloom;

vec2 ParallaxMapping(vec2 texCoord, vec3 viewDir);

void main()
{
    vec2 texCoords = TexCoord;
    if(handleParallax)
    {
        vec3 viewDir = normalize(TangentViewPos - TangentFragPos);
        texCoords = ParallaxMapping(TexCoord, viewDir);

        if(texCoords.x > 1.0 || texCoords.y > 1.0 || texCoords.x < 0.0 || texCoords.y < 0.0)
            texCoords = TexCoord;
    }
    gPosition = FragPos;
    gViewPosition = FragPosView;
    gViewNormal = normalize(ViewNormal);
    if(handleNormal)
    {
        gNormal = texture(normal_map, texCoords).rgb;
        gNormal = gNormal * 2.0 - 1.0;
        gNormal = normalize(TBN * gNormal); 
    }
    else
    {
        gNormal = normalize(Normal); 
    }

    if(handleDiffuse)
        gAlbedo = texture(text_diffuse, texCoords);
    else 
        gAlbedo = vec4(albedo.xyz, opacity);

    if(handleMetallic)
        gMetalRoughAOBloom.r = texture(metallic_map, texCoords).r;
    else
        gMetalRoughAOBloom.r = metallic;

    if(handleRoughness)
        gMetalRoughAOBloom.g = texture(roughness_map, texCoords).r;
    else
        gMetalRoughAOBloom.g = roughness;

    if(handleAO)
        gMetalRoughAOBloom.b = texture(ao_map, texCoords).r;
    else
        gMetalRoughAOBloom.b = 1.f;

    if(bloom)
        gMetalRoughAOBloom.a = 1.0f;
    else
        gMetalRoughAOBloom.a = 0.0f;

}

vec2 ParallaxMapping(vec2 texCoords, vec3 viewDir)
{ 
    const float minLayers = 8.0;
    const float maxLayers = 32.0;
    float numLayers = mix(maxLayers, minLayers, abs(dot(vec3(0.0, 0.0, 1.0), viewDir))); 

    float layerDepth = 1.0 / numLayers;
    float currentLayerDepth = 0.0;

    vec2 P = viewDir.xy / viewDir.z * height_scale; 
    vec2 deltaTexCoords = P / numLayers;

    vec2  currentTexCoords     = texCoords;
    float currentDepthMapValue = texture(height_map, currentTexCoords).r;
  
    while(currentLayerDepth < currentDepthMapValue)
    {
        currentTexCoords -= deltaTexCoords;
        currentDepthMapValue = texture(height_map, currentTexCoords).r;  
        currentLayerDepth += layerDepth;  
    }

    vec2 prevTexCoords = currentTexCoords + deltaTexCoords;
    float afterDepth  = currentDepthMapValue - currentLayerDepth;
    float beforeDepth = texture(height_map, prevTexCoords).r - currentLayerDepth + layerDepth;
    float weight = afterDepth / (afterDepth - beforeDepth);

    vec2 finalTexCoords = prevTexCoords * weight + currentTexCoords * (1.0 - weight);

    return finalTexCoords; 
} 