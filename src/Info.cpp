#include "Info.h"
#include <iostream>
#include "GameMenu/FontHolder.h"  
#include "GUI/Sound.h"

Info::Info() :m_numLevel {1}
{}

void Info::draw(sf::RenderWindow& window)
{
    auto text = FontHolder::getText();

    text.setString("Money: " + std::to_string(m_money) );

    text.setFillColor(sf::Color::Black);

    sf::View view = window.getView();
    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();

    float padding = 20.f;
    sf::Vector2f pos;
    pos.x = center.x - size.x / 2.f + padding;
    pos.y = center.y + size.y / 2.f - text.getCharacterSize() - padding;
    text.setPosition(pos);
    window.draw(text);
}



bool Info::buyPlayer(TypeObject type, int price)
{

	if (m_money >= price) {

		m_typePlayer = type;
		m_money -= price;
        Sound::playSound(SoundType::unlock);
		return true;
	}
    Sound::playSound(SoundType::notification);

	return false;
}

