
#version 130

in vec3 position;
in vec3 colour;

out vec3 frag_colour;


uniform mat4 translate_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;

void main() {
      gl_Position = projection_matrix
		     * view_matrix
                     * translate_matrix
                     * vec4(position, 1.0);
 			frag_colour = colour;
}


