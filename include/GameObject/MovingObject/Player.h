#include "GameObject/MovingObject/MovingObject.h"
//#include "GameObject/Images/TypeObject.h"
#include "GameObject/Images/ImagesObject.h"

class Player : public MovingObject
{
public:
	Player(sf::Vector2f location, sf::Sprite sprite, TypeObject type);
	void print() { std::cout << "\n Player \n"; }
	virtual void move(float) override;
private:
	int m_speed = 150;
	int m_life = 5;
	sf::Vector2f m_firstLoc;


};