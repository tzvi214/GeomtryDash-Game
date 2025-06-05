#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject/Object.h"
#include"GameObject/Images/TypeObject.h"
#include"GameObject/Images/ImagesObject.h"

#include "Information.h"


class GameController
{
public:
	GameController();
	void run();
private:
	//-- function ----
	void mainLoop();
	void handleEvent();
	//--- data member ----
	Information m_information;
	sf::RenderWindow m_window;
};
