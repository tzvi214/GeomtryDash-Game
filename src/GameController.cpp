#include "GameController.h"
#include <iostream>
#include <fstream>
#include "GameObject/MovingObject/Player.h"
#include "GameObject/MovingObject/Enemy.h"
#include "GameObject/StaticObject/Obstacle.h"

GameController::GameController()
	: m_window(sf::VideoMode(800, 900), "Geometry Dash"), m_menuManager() 
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
			m_menuManager.runMenu(m_menuInfo, m_window);
			m_window.setView(sf::View(sf::FloatRect(0.f, 0.f, 800.f, 900.f)));

			handleMenu();
			updateAfterLevel();	
	}
	// i think its need to be like this ^

}
//-------------------------------------
void GameController::mainLoop()
{



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
	if (m_menuManager.needToStart())
	{
		analyzeLevel();
		mainLoop();
	}
	else if (m_menuManager.needToExit())
	{
		m_need2exit = true;
		//m_window.close();
	}
}
//-------------------------------------
void GameController::analyzeLevel()
{
	ImagesObject images;



	std::fstream file("level" + std::to_string(m_information.getNumLevel()) + ".txt");
	if (!file.is_open())
	{
		std::cerr << "Error: Failed to open file: Level" << m_information.getNumLevel() << ".txt" << std::endl;
		return;
	}

	// Add logic to read from the file here...
	char c;
	int row = 0, col = 0;
	while (file >> std::noskipws >> c) {

		if (c == '#') {
			std::cout << "#  " << row << "," << col << std::endl;
			sf::Vector2f loc{ static_cast<float>(col) * 50.f, static_cast<float>(row) * 50.f };
			m_staticObjVec.push_back(std::make_unique<Obstacle>(loc, images.getObstacleSprite()));

		}
		else if (c == '@') {
			std::cout << "@  " << row << "," << col << std::endl;
			sf::Vector2f loc{ static_cast<float>(col) * 50.f, static_cast<float>(row) * 50.f };
			m_movingObjVec.push_back(std::make_unique<Enemy>(loc, images.getEnemySprite()));
		}

		else if (c == 'p') {
			std::cout << "p  " << row << "," << col << std::endl;

			sf::Vector2f loc{ static_cast<float>(col) * 50.f, static_cast<float>(row) * 50.f };
			m_movingObjVec.push_back(std::make_unique<Player>(loc, images.getPlayerSprite()));
		}
		col++;
		if (c == '\n')
		{
			row++;
			col = 0;
		}
	}
	  
	file.close();


	
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

}
