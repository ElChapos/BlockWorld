#version 130

in vec3 position;
in vec3 color;

out vec3 frag_color;

uniform mat4 cam_proj;
uniform mat4 cam_view;
uniform mat4 cam_mod;

void main()
{
	gl_Position = (cam_proj * cam_view * cam_mod) * vec4(position, 1);
	frag_color = color; 
}
