#include "GameMenu/PlayerEpsilon.h"

PlayerEpsilon::PlayerEpsilon(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:CharactersButton(location, wantedSize)
{
	m_cost = ButtonData::COST_PLAYER_EPSILON;
	m_costText.setString(std::to_string(m_cost));

	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayerEpsilon);
	scaleCharacters(wantedSize);
}

MenuAction PlayerEpsilon::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayerEpsilon, m_cost))
		return MenuAction::BuySucceed;

	return MenuAction::None;
}