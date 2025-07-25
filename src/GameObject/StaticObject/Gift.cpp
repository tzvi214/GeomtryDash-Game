#include "GameObject/StaticObject/Gift.h"
#include "GameObject/Factory.h" 
#include "GUI/Sound.h"

Gift::Gift(sf::Vector2f location, sf::Sprite sprite)
	: StaticObject(location, sprite) {
}


bool Gift::m_registerIt = Factory::registerIt(CHAR::GIFT,
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<Gift>(objectConfig.location, objectConfig.images.getSpriteObject(TypeObject::Gift));
	});

void Gift::handleCollision(Player& player)
{
	m_addCoin = true;
	m_dead = true; // delete this Coin from vector
	Sound::playSound(SoundType::touchGift);
}

void Gift::updateInformation(ObjectInformation& info)
{
	if (m_addCoin)
		info.addCoins(1); // Notify the game controller to add a coin

	m_addCoin = false; // Reset the flag after notifying	
}
