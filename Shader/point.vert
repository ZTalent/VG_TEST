#version 330 core

layout(location=0) in vec3 aPos;
layout(location=1) in vec3 aColor;
layout(location=2) in float t;
out vec3 ourColor;

uniform float R;
uniform bool isCircle;
uniform vec3 CenterPosition;
uniform vec3 CColor;

const float PI=3.1515926f;

vec2 ComputeCircle(in float t)
{
     return vec2(R*cos(2*PI*t),R*sin(2*PI*t));
}

void main()
{
   if(isCircle)
   {
       gl_Position=vec4(CenterPosition.xy+ComputeCircle(t),0.0,1.0);
       ourColor=CColor;
   }
   else
   {
        gl_Position=vec4(aPos,1.0);
      ourColor=aColor;
   }
}