#include "GameController.h"
#include <iostream>
#include <fstream>
#include "GameObject/MovingObject/Player.h"

GameController::GameController()
	: m_window(sf::VideoMode(800, 900), "Geometry Dash"), m_menuManager(m_window) 
{
	readFromFile();

}
//-------------------------------------
void GameController::run()
{
	/*while (m_window.isOpen()) {

		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window.close();
				return;
			}
			m_menuManager.showMenu(event);
			handleMenu();
			mainLoop();
			updateAfterLevel();
		}

	}*/
	while (!m_need2exit) {

		    sf::Event event;
			m_window.setView(sf::View(sf::FloatRect(0.f, 0.f, 800.f, 900.f)));
			m_menuManager.runMenu(event);
			m_window.setView(sf::View(sf::FloatRect(0.f, 0.f, 800.f, 900.f)));

			handleMenu();
			updateAfterLevel();	
	}
	// i think its need to be like this ^

}
//-------------------------------------
void GameController::mainLoop()
{
	sf::Texture avatar;
	if (!avatar.loadFromFile("Avatar.png")) {
		std::cerr << "Error: Failed to load Avatar.png" << std::endl;
		return;
	}
	sf::Sprite avaterSprite;
	avaterSprite.setTexture(avatar);

	sf::Vector2f loc{ 400.f, 450.f };
	TypeObject playerType = TypeObject::player;

	m_movingObjVec.push_back(std::make_unique<Player>(loc, avaterSprite, playerType));
	m_clock.restart();// not to get a lot of time itch time that the function called
	while (m_window.isOpen()) {

		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				/*m_window.close();
				m_need2exit = true;*/
				return;
			}
		}
		handleEvent();
		handleCollisionController();
		draw();

	}
}
//-------------------------------------
void GameController::handleEvent()
{
	deleteObjFromVec();
	// maybe move is separate function and update direction is a separate function
	for (const auto& MovObj : m_movingObjVec)
		MovObj->updateDirection();

	auto deltaTime = m_clock.restart().asSeconds();
	for (const auto& MovObj : m_movingObjVec)
		MovObj->move(deltaTime);

	auto view = m_window.getView();
	view.move(sf::Vector2f{ deltaTime * 150, 0.f });
	m_window.setView(view);

}
//-------------------------------------
void GameController::deleteObjFromVec()
{
	std::erase_if(m_movingObjVec, [](const auto& obj) { return obj->isDead(); });
	//std::erase_if(m_staticObjVec, [](const auto& obj) { return obj->isDead(); });// maybe in i will be able to shot static object and to kill them
}
//-------------------------------------
void GameController::draw()
{
	m_window.clear();
	for (const auto& staticObj : m_staticObjVec)
		staticObj->draw(m_window);
	for (const auto& movingObj : m_movingObjVec)
		movingObj->draw(m_window);

	m_information.draw(m_window);
	m_window.display();
}
//-------------------------------------
void GameController::handleCollisionController()
{


}
//-------------------------------------
void GameController::handleMenu()
{
	if (m_menuManager.handleStart())
	{
		analyzeLevel();
		mainLoop();
	}
	else if (m_menuManager.handleExit())
	{
		m_need2exit = true;
		//m_window.close();
	}
}
//-------------------------------------
void GameController::analyzeLevel()
{
	// anlayze ...
	
	
  // Analyze level...  
       /*sf::Texture avatar;  
       if (!avatar.loadFromFile("Avatar.png")) {  
           std::cerr << "Error: Failed to load Avatar.png" << std::endl;  
           return;  
       }  
	   sf::Sprite avaterSprite;
	   avaterSprite.setTexture(avatar);

	   sf::Vector2f loc{ 400.f, 450.f };
	   TypeObject playerType = TypeObject::player;

	   m_movingObjVec.push_back(std::make_unique<Player>(loc, avaterSprite, playerType));*/
}
//-------------------------------------
void GameController::updateInformation()
{
}
//-------------------------------------
void GameController::updateAfterLevel()
{
	m_movingObjVec.clear();
	m_staticObjVec.clear();
}

void GameController::readFromFile()
{
   std::fstream file("Level" + std::to_string(m_information.getNumLevel()) + ".txt");
   if (!file.is_open())
   {
       std::cerr << "Error: Failed to open file: Level" << m_information.getNumLevel() << ".txt" << std::endl;
       return;
   }

   // Add logic to read from the file here...
   char c;
   int row = 0, col=0;
   while (file >> std::noskipws >> c) {
	   if (c == '#')
		   std::cout << "#  " << row << "," << col << std::endl;
	   else if (c == '@')
		   std::cout << "@  " << row << "," << col << std::endl;
	   col++;
	   if (c == '\n')
	   {
		   row++;
		   col = 0;
	   }
   }

   file.close();
}
