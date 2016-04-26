#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>
#include <memory>
#include <utility>
#include <ostream>

class BoundingBox {
	public:
		BoundingBox(glm::vec3);

		//void SetBounds(glm::vec3);
		//bool CollidesWith(glm::vec3);
		//glm::vec3 GetVec3();

	private:
		glm::vec3 position;

		//glm::vec3 bounding_box;
};
