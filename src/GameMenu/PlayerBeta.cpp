#include "GameMenu/PlayerBeta.h"

PlayerBeta::PlayerBeta(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	: CharactersButton(location, wantedSize)
{
	m_cost = ButtonData::COST_PLAYER_BETA;    
	m_costText.setString(std::to_string(m_cost));

	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayeraBeta);
	scaleCharacters(wantedSize);
}

MenuAction PlayerBeta::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayeraBeta, m_cost))
		return MenuAction::BuySucceed;

	return MenuAction::None;
}
