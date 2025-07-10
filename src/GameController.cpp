#include "GameController.h"
#include <iostream>
#include <fstream>
#include "GameObject/MovingObject/Player.h"
#include "GameObject/MovingObject/Enemy.h"
#include "GameObject/StaticObject/Obstacle.h"
#include "GameObject/Factory.h"
#include "GameMenu/MenuAction.h"
#include "GameData.h"
#include <chrono>
#include "GUI/Sound.h"


GameController::GameController()
	: m_window(sf::VideoMode((unsigned int) GameData::SIZE_GAME_WINDOW.x, (unsigned int)GameData::SIZE_GAME_WINDOW.y), "Geometry Dash"), m_menuManager(), m_background{ "bg.png" }
{

	readFromFile();
}
//-------------------------------------
void GameController::run()
{
	
	while (!m_need2exit) {

		m_window.setView(sf::View(sf::FloatRect(0.f, 0.f, GameData::SIZE_GAME_WINDOW.x, GameData::SIZE_GAME_WINDOW.y)));
		m_menuManager.runMenu(m_menuInfo, m_window);
		m_window.setView(sf::View(sf::FloatRect(0.f, 0.f, GameData::SIZE_GAME_WINDOW.x, GameData::SIZE_GAME_WINDOW.y)));

		handleMenu();
	}

}
//-------------------------------------
void GameController::mainLoop()
{

	m_clock.restart();// not to get a lot of time itch time that the function called
	while (m_window.isOpen()) {

		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				
				return;
			}
		}
		updateInformation();
		handleEvent();
		handleCollisionController();
		draw();

		if (m_objectInformation.isNextLevel())
		{

			m_objectInformation.setNextLevel(false);
			return;
		}

	}
}
//-------------------------------------
void GameController::handleEvent()
{
	deleteObjFromVec();
	auto deltaTime = m_clock.restart().asSeconds();
	for (const auto& MovObj : m_movingObjVec)
		MovObj->move(deltaTime);

	auto view = m_window.getView();
	view.move(sf::Vector2f{ deltaTime * 150, 0.f });// need to chinged it to  view.move(sf::Vector2f{ deltaTime * MOVE::SPEED, 0.f });
	
	m_window.setView(view);

}
//-------------------------------------
void GameController::deleteObjFromVec()
{
	std::erase_if(m_movingObjVec, [](const auto& obj) { return obj->isDead(); });
	std::erase_if(m_staticObjVec, [](const auto& obj) { return obj->isDead(); });// maybe in i will be able to shot static object and to kill them
}
//-------------------------------------
void GameController::draw()
{
	m_window.clear();
	m_background.draw(m_window);
	for (const auto& staticObj : m_staticObjVec)
		staticObj->draw(m_window);
	for (const auto& movingObj : m_movingObjVec)
		movingObj->draw(m_window);

	m_objectInformation.draw(m_window, m_numLevel);

	m_window.display();

}
//-------------------------------------
void GameController::handleCollisionController()
{
	for (auto& movingObj : m_movingObjVec)
	{
		for (auto& staticObj : m_staticObjVec)
		{
			if (movingObj->collidesWith(*staticObj))
				movingObj->handleCollision(*staticObj);
		}

		for (auto& otherMovingObj : m_movingObjVec)
		{
			if (movingObj->collidesWith(*otherMovingObj) && movingObj->checkCollision(*otherMovingObj))
				movingObj->handleCollision(*otherMovingObj);
		}
	}

}
//-------------------------------------
void GameController::handleMenu()
{
	ImagesObject images;

	MenuAction action = m_menuManager.runMenu(m_menuInfo, m_window);
	if (action == MenuAction::StartLevel )
	{

		analyzeLevel();
		playLoopMusic();
		mainLoop();
		updateAfterLevel();


	}
	else if (action == MenuAction::ExitGame)
	{
		m_need2exit = true;
	}
}
//-------------------------------------
void GameController::analyzeLevel()
{
	ImagesObject images;

	std::fstream file("level" + std::to_string(m_numLevel) + ".txt");
	if (!file.is_open())
	{
		std::cerr << "Error: Failed to open file: Level" << m_menuInfo.getNumLevel() << ".txt" << std::endl;
		return;
	}

	char c;
	int row = 0, col = 0;
	int counter = 0;
	while (file >> std::noskipws >> c) {
	
		sf::Vector2f loc{ static_cast<float>(col) * 50.f, static_cast<float>(row) * 50.f};// 50.f is the size of object
		ObjectConfig objectConfig{loc, images,m_menuInfo.getTypePlayer() };

		auto obj = Factory::create(c, objectConfig);
		if (auto mo = dynamic_cast<MovingObject*>(obj.get()))
			m_movingObjVec.push_back(std::unique_ptr<MovingObject>(static_cast<MovingObject*>(obj.release())));
		else if (auto so = dynamic_cast<StaticObject*>(obj.get()))
			m_staticObjVec.push_back(std::unique_ptr<StaticObject>(static_cast<StaticObject*>(obj.release())));
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
	for (auto& movingObj : m_movingObjVec)
	{
			movingObj->updateInformation(m_objectInformation);
	}

	for (auto& staticObj : m_staticObjVec)
	{
		staticObj->updateInformation(m_objectInformation);
	}

}
//-------------------------------------
void GameController::updateAfterLevel()
{
	
	m_numLevel++;
	m_menuInfo.getMoney(m_objectInformation.moveCoins());
	m_movingObjVec.clear();
	m_staticObjVec.clear();
}

void GameController::readFromFile()
{

}

void GameController::playLoopMusic()
{
	Sound::playMusic(MusicType::GameSound);
}