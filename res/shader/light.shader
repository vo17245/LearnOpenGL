#vertex_shader
#version 330 core
layout (location = 0) in vec3 a_Pos;
layout (location = 1) in vec3 a_Norm;
layout (location=2) in vec2 a_TexCoord;
uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;
out vec3 v_Norm;
out vec3 v_FragPos;
out vec2 v_TexCoord;
void main()
{
    v_TexCoord=a_TexCoord;
    v_Norm= vec3(mat4(transpose(inverse(u_Model))) * vec4(a_Norm, 0.0));
    gl_Position = u_Projection*u_View*u_Model*vec4(a_Pos, 1.0);
    //gl_Position=gl_Position/gl_Position.w;
    v_FragPos = vec3(u_Model * vec4(a_Pos, 1.0));
}

#fragment_shader
#version 330 core
out vec4 FragColor;
uniform vec3 u_LightColor;
in vec3 v_Norm;
uniform vec3 u_LightPos;
uniform vec3 u_LightDirection;
in vec3 v_FragPos; 
uniform sampler2D u_Texture;
in vec2 v_TexCoord;
struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
}; 
uniform Material material;

void main()
{
    //ambient
    vec3 ambient = vec3(texture(material.diffuse,v_TexCoord)) ;
    //diffuse
    vec3 norm = normalize(v_Norm);
    //vec3 lightDir = normalize(u_LightPos-v_FragPos); //入射光的反方向
    vec3 lightDir = normalize(-u_LightDirection);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = vec3(texture(material.diffuse,v_TexCoord))*diff; 
    //specular
    vec3 viewDir = normalize(-v_FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    if(dot(reflectDir,norm)<0)
    {
        spec=0;
    }
    vec3 specular = vec3(texture(material.specular,v_TexCoord)) * spec ; 
    vec3 objectColor=vec3(texture(u_Texture,v_TexCoord));
    vec3 result = (specular+ambient + diffuse) * u_LightColor;
    
    FragColor = vec4(result, 1.0);
    
} 