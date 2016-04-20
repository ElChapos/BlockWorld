#include <map>
#include <string>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

class ColourManager {
	public:
		ColourManager();

		void AddColour(std::string, glm::vec3);
		glm::vec3 GetColour(std::string);

	private:
		std::map<std::string, glm::vec3> colour_list;
};
