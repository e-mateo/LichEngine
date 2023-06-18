##vert##
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;
layout(location = 3) in vec3 aTangent;
layout(location = 4) in vec3 aBiTangent;
layout(location = 5) in ivec4 boneIndices;
layout(location = 6) in vec4 boneWeights;

uniform mat4 mvp;
uniform mat4 boneMatrices[100];
uniform bool isAnimated;

uniform vec3 viewPos;

void main()
{
    if (isAnimated)
    {
        vec4 pos = vec4(0,0,0,0);
        vec3 localNormal = vec3(0,0,0);

        for (int i = 0; i < 4; i++)
        {
            if (int(boneIndices[i]) == -1)
                continue;

            pos += (boneMatrices[int(boneIndices[i])] * vec4(aPos, 1.f)) * boneWeights[i];
        }
        gl_Position = mvp * vec4(pos.xyz, 1.0);
    }
    else
    { 
        gl_Position = mvp * vec4(aPos, 1.0);
    }
}

##frag##
#version 330 core

uniform ivec4 id;

out vec4 FragColor;

void main()
{
    FragColor = vec4(id.x / 255.0, id.y / 255.0, id.z / 255.0, id.w / 255.0);
}