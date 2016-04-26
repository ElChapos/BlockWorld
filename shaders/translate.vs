
#version 130

in vec3 position;
in vec3 colour;

out vec3 frag_colour;


uniform mat4 cam_mod;
uniform mat4 cam_view;
uniform mat4 cam_proj;

void main() {
      gl_Position = cam_proj
		     * cam_view
                     * cam_mod
                     * vec4(position, 1.0);
 			frag_colour = colour;
}

