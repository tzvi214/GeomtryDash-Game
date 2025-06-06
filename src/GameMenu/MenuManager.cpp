#include "GameMenu/MenuManager.h"

MenuManager::MenuManager(sf::RenderWindow& window)
	:m_window(window)
{
	m_button.push_back(std::make_unique<Start>(ButtonData::LOC_START, ButtonData::SIZE_BUTTON));
	m_button.push_back(std::make_unique<Exit>(ButtonData::LOC_EXIT, ButtonData::SIZE_BUTTON));
	m_button.push_back(std::make_unique<Help>(ButtonData::LOC_HELP, ButtonData::SIZE_BUTTON));
	m_button.push_back(std::make_unique<Store>(ButtonData::LOC_STORE, ButtonData::SIZE_BUTTON));
}

void MenuManager::handleButtonClick(const sf::Vector2f& mousePos, sf::Event& event)
{
	for (int i = 0; i < m_button.size(); i++) {
		if (m_button[i]->isPressed(mousePos))
			m_button[i]->handleClick(m_stateButton, m_window, event);
	}
}

void MenuManager::showMenu(sf::Event& e)

{
	sf::Event event;
	// setAll באבא
	m_stateButton.setExit(false);
	m_stateButton.setStart(false);
	m_stateButton.setHelp(false);
	m_stateButton.setStore(false);

	while (!handleStart() || !handleExit()){
		// draw menu
		m_window.clear();

		for (int i = 0; i < m_button.size(); i++)
			m_button[i]->draw(m_window);

		m_window.display();


		// evant
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::MouseButtonPressed) { // בדיקה אם כפתור נלחץ
				sf::Vector2f mousePos = m_window.mapPixelToCoords(
					sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

				handleButtonClick(mousePos, event);
			}
		}
	}

}

bool MenuManager::handleStart() const
{
	return m_stateButton.isStart();
}

bool MenuManager::handleExit() const
{
	return m_stateButton.isExit();
}
