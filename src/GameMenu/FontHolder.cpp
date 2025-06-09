#include "GameMenu/FontHolder.h"

sf::Font FontHolder::m_font;

void FontHolder::loadFont()//thus need to be in the c-tor
{
	if (!m_font.loadFromFile("Athelas.ttc"))
		std::cerr << "Loading the font file failed";
}

sf::Text FontHolder::getText()
{
	sf::Text text;
	text.setFont(m_font);
	text.setCharacterSize(30); 
	return text;
}

