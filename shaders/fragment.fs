#version 130

in vec3 frag_colour;
out vec4 out_colour;

void main()
{
	out_colour = vec4(frag_colour, 1.0f);
}
