#include"GameObject/MovingObject/Move/BasicMove.h"

void Move::update(float deltaTime, sf::Vector2f& posObj)
{
	if (m_onGround)
	{
		m_velocityY = 0.f; // Reset vertical velocity when on ground
		return; // No need to update position if on ground
	}
	
	// -800 --> 0 --> +800 (�� ������ ����� ������ �� ����)
	m_velocityY += m_gravity * deltaTime;
	
    // valocityY. ������ �� 
    // ��� ����� ���� ���� �0 �������� ���� ���� ��� . 
    //��� �� ����� �������� ����� ��� ������ ����� ������ ����� ������
	posObj.y += m_velocityY * deltaTime;
}

void Move::startJump()
{
	if (m_onGround)
	{
		m_onGround = false; // Set onGround to false when jumping
		m_velocityY = m_jumpSpeed; // Set the initial jump speed
	}
}

void Move::setOnGround(bool onGround)
{
	m_onGround = onGround;
}
