#include "GameMenu/PlayerAlpha.h"

PlayerAlpha::PlayerAlpha(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
    : CharactersButton(location, wantedSize)
{
	m_cost = ButtonData::COST_PLAYER_ALPHA;
	m_costText.setString(std::to_string(m_cost));

	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayeraAlpha);
	scaleCharacters(wantedSize);
}


MenuAction PlayerAlpha::handleClick(Info& info, sf::RenderWindow& window)
{
	////info.setNumLevel(1); // need to change
	if (info.buyPlayer(TypeObject::PlayeraAlpha, m_cost))
		return MenuAction::BuySucceed;

	return MenuAction::None;
}

