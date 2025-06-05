#include "GameObject/StaticObject/StaticObject.h"
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"
#include "Information.h"
int main()
{
	sf::Sprite sprite;
	sf::Vector2f loc;
	TypeObject type = TypeObject::player;
	StaticObject staticObj(loc, sprite, type);
	staticObj.p();
	Information(7);
}
	
