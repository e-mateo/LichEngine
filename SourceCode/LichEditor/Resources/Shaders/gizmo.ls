##vert##
#version 330 core
layout(location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 mvp;

void main()
{
    gl_Position = mvp * vec4(aPos.xyz, 1.0);
}

##frag##
#version 330 core

layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

uniform vec3 color;

void main()
{
    FragColor = vec4(color, 1.0f);
    BrightColor = vec4(0,0,0,0);
}