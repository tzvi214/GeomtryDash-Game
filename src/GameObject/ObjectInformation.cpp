#include "GameObject/ObjectInformation.h"  
#include "GameMenu/FontHolder.h"  


void ObjectInformation::draw(sf::RenderWindow& window, int level) const{

    auto text = FontHolder::getText();

    text.setString("Level: " + std::to_string(level) + "    Coins: " + std::to_string(m_coins));

    text.setFillColor(sf::Color::Black);

    sf::View view = window.getView();
    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();

    float padding = 20.f;
    sf::Vector2f pos;
    pos.x = center.x - size.x / 2.f + padding;
    pos.y = center.y + size.y / 2.f - text.getCharacterSize() - padding;
    text.setPosition(pos);
    window.draw(text);
}
