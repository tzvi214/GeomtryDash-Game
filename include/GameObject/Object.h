#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"
class Object
{
public:
	Object(sf::Vector2f location, sf::Sprite& sprite, TypeObject type);
	virtual ~Object() = default;
	virtual void draw(sf::RenderWindow& window) {m_sprite.setPosition(m_location) ; window.draw(m_sprite); };

protected:

	sf::Vector2f m_location;
	sf::Sprite m_sprite;
	TypeObject m_type;
};