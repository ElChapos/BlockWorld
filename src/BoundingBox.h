#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

class BoundingBox {
	public:
		BoundingBox(glm::vec3);

		void SetBounds(glm::vec3);

	private:
		glm::vec3 bounding_box;
};