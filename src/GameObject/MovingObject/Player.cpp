#include "GameObject/MovingObject/Player.h"

Player::Player(sf::Vector2f location, sf::Sprite sprite, TypeObject type)
	: MovingObject(location, sprite, type) {}
