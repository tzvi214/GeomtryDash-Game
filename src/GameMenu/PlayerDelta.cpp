#include "GameMenu/PlayerDelta.h"

PlayerDelta::PlayerDelta(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:CharactersButton(location, wantedSize)
{
	m_cost = ButtonData::COST_PLAYER_DELTA;
	m_costText.setString(std::to_string(m_cost));

	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayerDelta);
	scaleCharacters(wantedSize);
}

MenuAction PlayerDelta::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayerDelta, m_cost))
		return MenuAction::BuySucceed;

	return MenuAction::None;
}