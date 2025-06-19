#pragma once
#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/Images/ImagesObject.h"

class Enemy : public MovingObject
{
public:
	Enemy(sf::Vector2f location, sf::Sprite sprite);
	~Enemy() override = default;
	virtual void move(float deltaTime) override;

	virtual void handleCollision(MovingObject&) override;
	virtual void handleCollision(StaticObject&) override;
	virtual void handleCollision(Player&) override;

	// if the enemy collides with a other enemy,  ??????

private:
	sf::Vector2f m_direction = { 1.f, 0.f };	// Default direction to the right

	// static : So that the registry is created at compile time.
	// bool : give some type to the variable, no matter what.
	static bool m_registerIt;
};

/*
* ���� ���� ����� �� ���� ���� �� ���� ��� ��� ����� �����
* ������� �� ����� ���� ��
* ������� �� ���� ���� ��
* ������ �� ���������� 
* 
*/


// ��� ���� ���� �� ����� ����� 