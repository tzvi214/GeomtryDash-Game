#include "GameMenu/Button.h"

Button::Button(const GameObjectType& type, const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:m_type(type), m_location(location)
{
	updateSpritesForAll(wantedSize);
}

bool Button::isPressed(const sf::Vector2f& mousePos) const
{
	return m_sprite.getGlobalBounds().contains(mousePos);
}



void Button::updateSpritesForAll(const sf::Vector2f& wantedSize)
{
	switch (m_type)
	{
	case GameObjectType::Start:
		m_sprite = ImageMenu::getSpinte(GameObjectType::Start, wantedSize);
		break;

	case GameObjectType::Store:
		m_sprite = ImageMenu::getSpinte(GameObjectType::Store, wantedSize);
		break;

	case GameObjectType::Help:
		m_sprite = ImageMenu::getSpinte(GameObjectType::Help, wantedSize);
		break;

	case GameObjectType::Exit:
		m_sprite = ImageMenu::getSpinte(GameObjectType::Exit, wantedSize);
		break;

	case GameObjectType::Watch:
		m_sprite = ImageMenu::getSpinte(GameObjectType::Watch, wantedSize);
		break;

	case GameObjectType::GitHub:
		m_sprite = ImageMenu::getSpinte(GameObjectType::GitHub, wantedSize);
		break;

	case GameObjectType::Done:
		m_sprite = ImageMenu::getSpinte(GameObjectType::Done, wantedSize);
		break;

	case GameObjectType::Cancel:
		m_sprite = ImageMenu::getSpinte(GameObjectType::Cancel, wantedSize);
		break;

	default:
		break;
	}
}


void Button::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location); // עדכון מיקום התמונה
	window.draw(m_sprite);
}
