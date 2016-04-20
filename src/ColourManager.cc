#include "ColourManager.h"

ColourManager::ColourManager(){}

void ColourManager::AddColour(std::string colour, glm::vec3 rgb)
{
	colour_list[colour] = rgb;
}

glm::vec3 ColourManager::GetColour(std::string colour)
{
	if(m.find(colour) == m.end())
	{
		return glm::vec3(0.0, 0.0, 0.0);
	}
	else
	{
		return colour_list[colour];
	}
}
