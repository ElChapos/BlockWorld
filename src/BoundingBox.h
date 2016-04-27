#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>
#include <memory>
#include <utility>
#include <ostream>

class BoundingBox {
	public:
		BoundingBox(glm::vec3, int);

		glm::vec3 GetVec3();
		glm::mat4 GetModelTransformation();

		void Translate(glm::vec3);
		void Scale();
		void Rotate();

	private:
		glm::vec3 position;
		int type;
		glm::mat4 translate_matrix;

};
