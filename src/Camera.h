#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GL/glew.h>
#include <GL/gl.h>

class Camera{
    public:
        Camera();
        
        void Draw();
        void UpdateFacingDirection();
        void MoveCamera(glm::vec2, glm::vec2);
        void CameraController(int);

        glm::vec3 GetOffset();
        
        glm::mat4 GetProjection();
        glm::mat4 GetView();
        glm::vec3 GetPosition();
        
        void SetBlockDistance(int);
        int GetBlockDistance();
        
    private:
		GLfloat camera_speed = 0.1;
		GLfloat camera_x = 0.0;
		GLfloat camera_y = 0.0;

		double point = 0.39375;
		int block_dist = 3;
        
		std::string f_pos = "N";

		glm::vec3 offset_pos;
		glm::vec3 position = glm::vec3(0, 0, -3);
		glm::vec3 z_direction;
		glm::vec3 x_direction;
		
		glm::mat4 cam_proj;
		glm::mat4 cam_view;
		
};