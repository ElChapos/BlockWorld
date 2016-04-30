#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>
#include <memory>
#include <utility>
#include <ostream>

class BoundingBox {
	public:
		BoundingBox(glm::vec3, int, float, glm::vec3);

		glm::vec3 GetVec3();
		glm::mat4 GetModelTransformation();
		glm::vec3 GetMaxAndMin(int);

		void Translate(glm::vec3);
		void Scale(float);
		void Rotate(glm::vec3);
		void CheckCollision(glm::vec3, glm::vec3, glm::vec3, glm::vec3);


	private:
		glm::vec3 position;
        glm::vec3 rotation;
		float scale;
		int type;
		glm::mat4 translate_matrix;
        glm::mat4 scale_matrix;
        glm::mat4 model_matrix;


};
