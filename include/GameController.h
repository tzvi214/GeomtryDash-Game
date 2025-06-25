#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameObject/Object.h"
#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/StaticObject/StaticObject.h"
#include"GameObject/Images/TypeObject.h"
#include"GameObject/Images/ImagesObject.h"
#include "GameMenu/MenuManager.h"
#include "Info.h"
#include "GameMenu/Background.h"
#include "GameObject/ObjectInformation.h"



class GameController
{
public:
	GameController();
	void run();
private:
	//-- function ----
	void handleMenu();
	void analyzeLevel();
	void mainLoop();
	void handleEvent();
	void deleteObjFromVec();
	
	void draw();
	void handleCollisionController();
	void updateInformation();

	void updateAfterLevel();
	void playLoopMusic();
	void readFromFile();
	//--- data member ----
	std::vector <std::unique_ptr<MovingObject>> m_movingObjVec;
	std::vector <std::unique_ptr<StaticObject>> m_staticObjVec;

	ObjectInformation m_objectInformation;
	sf::RenderWindow m_window;
	MenuManager m_menuManager;
	bool m_need2exit = false;// in class states
	sf::Clock m_clock;
	Info m_menuInfo;
	Background m_background;
	int m_numLevel = 1;

};
