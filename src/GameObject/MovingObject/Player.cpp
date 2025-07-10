#include "GameObject/MovingObject/Player.h"
#include "GameObject/StaticObject/StaticObject.h"
#include "GameObject/Factory.h" // for Factory class

Player::Player(sf::Vector2f location, sf::Sprite sprite): MovingObject(location, sprite), m_safeLoc(location),m_startLoc(location) {}

bool Player::m_registerIt = Factory::registerIt(CHAR::PLAYER,
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<Player>(objectConfig.location, objectConfig.images.getSpritePlayer(objectConfig.playerType));
	});

void Player::draw(sf::RenderWindow& window)

{
	if (objInView(window) && !m_need2dead) // Check if the object is in view before drawing
	{
		m_sprite.setPosition(m_location);
		window.draw(m_sprite);

		if (m_need2dead)
			returnToSafeLoc(window); 
	}
	else
	{
		returnToSafeLoc(window);	
	}
}

void Player::move(float deltaTime)
{
	setSafeLocation();
	MovingObject::move(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
 		m_move.startJump();
		m_onGround = false;
	}

} 

void Player::handleCollision(MovingObject& other)
{
	// Handle collision with another moving object
	other.handleCollision(*this); // Call the other object's collision handler
}

void Player::handleCollision(StaticObject& other)
{
	other.handleCollision(*this); // Delegate collision handling to the static object
}

void Player::handleCollision(Enemy& enemy)
{
	std::cout << "Player collided with Enemy. Player is Dead" << std::endl;
	m_need2dead = true; // Set the player need to dead
	// need to finished.
}


void Player::updateInformation(ObjectInformation& info)
{
	// if the player is dead or not in view, set the player dead state
	info.setPlayerDead(m_need2dead || !m_isInView);


	m_need2dead = false;
	m_isInView = true; 
}

void Player::setSafeLocation()
{
	if (!m_safeLocClock.getElapsedTime().asSeconds() >= 5.f)
		return;

	if ( m_onGround )
	{
		m_safeLoc.x = m_location.x - MOVE::SAVE_X;
		m_safeLoc.y = m_location.y;
		m_safeLocClock.restart();
	}
}

void Player::returnToSafeLoc(sf::RenderWindow& window)
{
	m_move.resetVelocityY();
    //m_location = m_safeLoc; // reset up-to safeLocation.
	m_location = m_startLoc; // reset up-to start Location.
	setView(window);
	m_need2dead = false;
}

void Player::setView(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);

	sf::View view = window.getView();
	float viewWidth = view.getSize().x;

	sf::Vector2f currentCenter = view.getCenter();

	sf::Vector2f newCenter;
	newCenter.x = m_location.x + (viewWidth * (0.5f - MOVE::playerViewOffsetX));
	newCenter.y = currentCenter.y; 

	view.setCenter(newCenter);
	window.setView(view);
}


