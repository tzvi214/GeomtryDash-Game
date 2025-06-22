#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class FontHolder {

public:
	static sf::Text getText();

private:
	static void loadFont();

	static bool m_loaded;

	static sf::Font m_font;

};
