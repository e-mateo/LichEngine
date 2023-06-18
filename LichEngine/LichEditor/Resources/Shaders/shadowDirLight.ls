##vert##
#version 450 core
layout (location = 0) in vec3 aPos;
layout(location = 5) in ivec4 boneIndices;
layout(location = 6) in vec4 boneWeights;

uniform mat4 lightSpaceMatrix;
uniform mat4 model;
uniform bool isAnimated;
uniform mat4 boneMatrices[200];

void main()
{
    vec4 position = vec4(0,0,0,0);
    if (isAnimated)
    {
        for (int i = 0; i < 4; i++)
        {
            if (int(boneIndices[i]) == -1)
                continue;

            position += (boneMatrices[int(boneIndices[i])] * vec4(aPos, 1.f)) * boneWeights[i];
        }
    }
    else
    {
        position = vec4(aPos, 1.0);
    }

    gl_Position = lightSpaceMatrix * model * position;
}


##frag##
#version 450 core

void main()
{             

}