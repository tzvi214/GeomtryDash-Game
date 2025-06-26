#include "GameMenu/CharactersButton.h"

CharactersButton::CharactersButton(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
    : Button(location)
{
    // יצירת ספרייט של מנעול
    m_lock = ImagesObject::getSpritLock(wantedSize);
    m_lock.setPosition(m_location);

    // טקסט של עלות הדמות
    m_costText = FontHolder::getText();
    m_costText.setCharacterSize(30);
    m_costText.setFillColor(sf::Color::White);
}

void CharactersButton::scaleCharacters(const sf::Vector2f& wantedSize)
{
    sf::FloatRect bounds = m_sprite.getLocalBounds();

    float scaleX = wantedSize.x / bounds.width;
    float scaleY = wantedSize.y / bounds.height;

    m_sprite.setScale(scaleX, scaleY);
}

void CharactersButton::drawLock(sf::RenderWindow& window) {
    window.draw(m_lock);
}

void CharactersButton::drawCost(sf::RenderWindow& window) {

    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    m_costText.setPosition(bounds.left + bounds.width / 2.f - m_costText.getLocalBounds().width / 2.f,
        bounds.top - m_costText.getLocalBounds().height - 5.f);

    window.draw(m_costText);
}

int CharactersButton::getCost() const
{
    return m_cost;
}
