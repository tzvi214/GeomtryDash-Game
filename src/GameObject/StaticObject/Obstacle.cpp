#include "GameObject/StaticObject/Obstacle.h"
#include "GameObject/MovingObject/Player.h"
#include "GameObject/Factory.h" // for Factory class

Obstacle::Obstacle(sf::Vector2f location, sf::Sprite sprite) :StaticObject(location, sprite)
{ }


bool Obstacle::m_registerIt = Factory::registerIt(CHAR::OBSTACLE,
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<Obstacle>(objectConfig.location, objectConfig.images.getSpriteObject(TypeObject::Obstacle));
	});

void Obstacle::handleCollision(Player& player)
{
	player.setNeed2Dead();
}
