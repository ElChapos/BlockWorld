#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>
#include <memory>
#include <utility>
#include <ostream>

class BoundingBox {
	public:
		BoundingBox(glm::vec3);

	private:
		glm::vec3 position;

};
