#version 330 core
layout (points) in;
layout (line_strip, max_vertices = 100) out;

in VS_OUT{
    vec3 color;
}gs_in[];

in float vSides[];

const float PI=3.1515926;

out vec3 fColor;

void build_house(vec4 position) {    
    fColor=gs_in[0].color;

    for(int i=0;i<=vSides[0];i++)
    {
        float ang=PI*2.0/vSides[0]*i;

        vec4 offset=vec4(cos(ang)*0.3,-sin(ang)*0.4,0.0,0.0);
        gl_Position=gl_in[0].gl_Position+offset;
        EmitVertex();
    }

    // gl_Position = gl_in[0].gl_Position + vec4(-0.2, -0.2, 0.0, 0.0); 
    // EmitVertex();

    // gl_Position = gl_in[0].gl_Position + vec4( 0.2, -0.2, 0.0, 0.0);
    // EmitVertex();

    // gl_Position = gl_in[0].gl_Position + vec4( 0.0, 0.3, 0.0, 0.0);
    // EmitVertex();

    // gl_Position = gl_in[0].gl_Position + vec4( 0.2, 0.2, 0.0, 0.0);
    // EmitVertex();
    
    // gl_Position = gl_in[0].gl_Position + vec4( 0.0, 0.4, 0.0, 0.0);
    // fColor=vec3(1.0,1.0 ,1.0 );
    // EmitVertex();
    EndPrimitive();
}

void main()
{
    build_house(gl_in[0].gl_Position);
}