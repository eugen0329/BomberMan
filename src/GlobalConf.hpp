#ifndef GLOBALCONF_SUWOTGJ7
#define GLOBALCONF_SUWOTGJ7

#include <string>
#include <SFML/Graphics.hpp>
#include "Common/Algorithms.hpp"

namespace conf {
	static sf::Font getFont(std::string name) {
		sf::Font f;
		f.loadFromFile(name);
		return f;
	}
	static const std::string backgroundGrid("res/mapGrid"); 
	static const std::string logoText("BOMBERMAN");

	static const int defaultTextHeight = 80;
	static const int btnTextHeight = defaultTextHeight;

	static const sf::Color defaultColor(84, 84, 84);
	static const sf::Color btnDefaultColor(defaultColor);

	static const std::string defaultFontName("./res/Arcade.ttf"); 
	static const sf::Font defaultFont = getFont(defaultFontName);
}


#endif /* end of include guard: GLOBALCONF_SUWOTGJ7 */
