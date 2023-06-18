##vert##
#version 450 core
layout (location = 0) in vec3 aPos;
layout(location = 5) in ivec4 boneIndices;
layout(location = 6) in vec4 boneWeights;

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

    gl_Position = model * position;
}

##geom##
#version 450 core
layout (triangles) in;
layout (triangle_strip, max_vertices=18) out;

uniform mat4 shadowMatrices[6];
out vec4 FragPos;

void main()
{
    for(int face = 0; face < 6; ++face)
    {
        gl_Layer = face; 
        for(int i = 0; i < 3; ++i) 
        {
            FragPos = gl_in[i].gl_Position;
            gl_Position = shadowMatrices[face] * FragPos;
            EmitVertex();
        }    
        EndPrimitive();
    }
} 

##frag##
#version 450 core
in vec4 FragPos;

uniform vec3 lightPos;
uniform float far_plane;

void main()
{
    float lightDistance = length(FragPos.xyz - lightPos);
   
    lightDistance = lightDistance / far_plane;
    
    gl_FragDepth = lightDistance;
}