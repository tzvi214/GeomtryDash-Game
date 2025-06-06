#pragma once
#include "Button.h"
#include "vector"

#include "Start.h"
#include "Exit.h"
#include "Help.h"
#include "Store.h"


class MenuManager {

public:
	MenuManager(sf::RenderWindow& window);


	void showMenu(sf::Event& event);
	bool handleStart() const; // מחזירה אם נלחץ כפתור התחלת משחק
	bool handleExit() const;

private:
	std::vector<std::unique_ptr<Button>> m_button;

	State m_stateButton;
	sf::RenderWindow& m_window;

	void handleButtonClick(const sf::Vector2f& mousePos, sf::Event& event); // בודקת אם כפתור נחלץ ומפעילה את התנהגות הכפתור

};