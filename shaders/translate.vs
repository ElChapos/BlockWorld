
#version 130

in vec3 position;
in vec3 colour;

out vec3 frag_colour;


uniform mat4 translateMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
      gl_Position = projectionMatrix
		     * viewMatrix
                     * translateMatrix
                     * vec4(position, 1.0);
 			frag_colour = colour;
}

