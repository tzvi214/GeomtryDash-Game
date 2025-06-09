#include "GameObject/MovingObject/Player.h"

Player::Player(sf::Vector2f location, sf::Sprite sprite, TypeObject type)
	: MovingObject(location, sprite, type) {}

void Player::move(float time)  
{  
 
   m_location.x += time * m_speed; // m_speed = 50  
   m_sprite.move(m_location.x, m_location.y); // Correctly passing x and y values to sf::Sprite::move  
 
}
