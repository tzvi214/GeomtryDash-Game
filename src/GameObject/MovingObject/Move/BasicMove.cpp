#include"GameObject/MovingObject/Move/BasicMove.h"

void Move::update(float deltaTime, sf::Vector2f& posObj)
{
	if (m_onGround)
	{
		m_velocityY = 0.f; 
		return; 
	}
	
	m_velocityY += m_gravity * deltaTime;
	
    
	posObj.y += m_velocityY * deltaTime;
}

void Move::startJump()
{
	if (m_onGround)
	{
		m_onGround = false; 
		m_velocityY = m_jumpSpeed; 
	}
}

void Move::setOnGround(bool onGround)
{
	m_onGround = onGround;
}
