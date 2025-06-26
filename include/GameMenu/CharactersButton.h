#pragma once
#include "Button.h"
#include "GameObject/Images/ImagesObject.h"
#include "GameObject/Images/TypeObject.h"
#include "GameMenu/FontHolder.h"
#include <SFML/Graphics.hpp>

class CharactersButton : public Button {
public:
    CharactersButton(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

    void scaleCharacters(const sf::Vector2f& wantedSize);
    void drawLock(sf::RenderWindow& window);
    void drawCost(sf::RenderWindow& window);

    int getCost() const; // How much does it cost

protected:
    sf::Sprite m_lock;
    int m_cost;
    sf::Text m_costText;
};
