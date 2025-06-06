#include "GameMenu/Help.h"

Help::Help(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(TypeButton::Help, location, wantedSize)
{
	m_instructionText = FontHolder::getText();
	m_instructionText.setString("Hi, My name is Aharon Shamsi"); // לרשום הוראות המשחק בקבועים סטרינג
	m_instructionText.setPosition(0, 0);
}

void Help::handleClick(State & state, sf::RenderWindow& window, sf::Event& event)
{
	state.setHelp(true);

	while (window.waitEvent(event)) {
		if (event.type == sf::Event::Closed)
			return;

		window.clear();
		window.draw(m_instructionText);
		window.display();
	}
}
