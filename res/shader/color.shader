#vertex_shader
#version 330 core
layout (location = 0) in vec3 a_Pos;
uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;
void main()
{
    gl_Position = u_Projection*u_View*u_Model*vec4(a_Pos, 1.0);
    gl_Position=gl_Position/gl_Position.w;
}

#fragment_shader
#version 330 core
uniform vec3 u_Color;
out vec4 FragColor;

void main()
{
    FragColor = vec4(u_Color, 1.0);
} 