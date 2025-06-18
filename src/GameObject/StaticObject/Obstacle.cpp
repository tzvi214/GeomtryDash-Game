#include "GameObject/StaticObject/Obstacle.h"
#include "GameObject/Factory.h"
#include "GameObject/Images/TypeObject.h"



Obstacle::Obstacle(sf::Vector2f location, sf::Sprite sprite) :StaticObject(location, sprite)
{
	// Additional initialization for Obstacle if needed
}

bool Obstacle::m_registerit = Factory::registerIt('#',
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<Obstacle>(objectConfig.location, objectConfig.images.getSpriteObject(TypeObject::Obstacle));
	});

void Obstacle::handleCollision(Object& other)
{
	other.handleCollision(*this); // Notify the other object about the collision
}
