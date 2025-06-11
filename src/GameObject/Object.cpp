#include "GameObject/Object.h"

Object::Object(sf::Vector2f location, sf::Sprite& sprite, TypeObject type)
	: m_location(location), m_sprite(sprite), m_type{ type }	
{
	m_sprite.setPosition(m_location);
}
