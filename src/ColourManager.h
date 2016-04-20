#include <map>
#include <string>

#include <glm/glm.hpp>

class ColourManager {
	public:
		ColourManager();

		void AddColour(std::string, glm::vec3);
		void GetColour(std::string);

	private:
		std::map<std::string, glm::vec3> colour_list;
};
