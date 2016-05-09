#include "ColourManager.h"

/**
 * ColourManager class initialisation
 * Does nothing as there are no initialisation requirements
 */
ColourManager::ColourManager(){}

/**
 * Allows the game to add a colour to allowed colours list
 * Takes in the colour name and a hacky vec3 for the RGB value
 */
void ColourManager::AddColour(std::string colour, glm::vec3 rgb)
{
	colour_list[colour] = rgb;
}

/**
 * Returns the requested colour.
 * Will return RGB for black if the colour is not in the list
 */
glm::vec3 ColourManager::GetColour(std::string colour)
{
	if(colour_list.find(colour) == colour_list.end())
	{
		return glm::vec3(0.0, 0.0, 0.0);
	}
	else
	{
		return colour_list[colour];
	}
}
