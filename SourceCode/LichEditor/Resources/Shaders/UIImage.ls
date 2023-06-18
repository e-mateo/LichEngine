##vert##
#version 450 core
layout (location = 0) in vec4 vertex;

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    TexCoords = vertex.zw;
    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);
}

##frag##
#version 450 core
layout (location = 0) out vec4 FragColor;
in vec2 TexCoords;
uniform float opacity;
uniform sampler2D image;

void main()
{    
    FragColor = texture(image, TexCoords);
    FragColor.w =  FragColor.w * opacity;
}  