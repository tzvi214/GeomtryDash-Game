#include "GameObject/StaticObject/ExitDoor.h"
#include "GameObject/Factory.h" // for Factory class
#include "GUI/Sound.h"

ExitDoor::ExitDoor(sf::Vector2f loc, sf::Sprite sprite) :StaticObject(loc, sprite){}

bool ExitDoor::m_registerIt = Factory::registerIt(CHAR::EXIT_DOOR,
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<ExitDoor>(objectConfig.location, objectConfig.images.getSpriteObject(TypeObject::ExitDoor));
	});

void ExitDoor::handleCollision(Player& player)
{
	m_nextLevel = true;
	Sound::playSound(SoundType::finishedLevel);

}

void ExitDoor::updateInformation(ObjectInformation& info)
{
	info.setNextLevel(m_nextLevel);
	m_nextLevel = false;
}