#version 330 core
layout(location=0) in vec2 pos;
layout(location=1) in vec3 aColor;
layout(location=2) in float side;

out VS_OUT{
    vec3 color;
}vs_out;

out float vSides;

void main()
{
    gl_Position=vec4(pos,0.0 ,1.0);
    vs_out.color=aColor;
    vSides=side;
}