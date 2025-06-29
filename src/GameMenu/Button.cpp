#include "GameMenu/Button.h"
#include "GUI/Sound.h"

Button::Button(const sf::Vector2f& location)
	:m_location(location)
{}

bool Button::isPressed(const sf::Vector2f& mousePos) const
{

	if (m_sprite.getGlobalBounds().contains(mousePos)) {
		Sound::playSound(SoundType::click);
		return true;
	}
	return  false;
}

void Button::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);
	window.draw(m_sprite);
}
