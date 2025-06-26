#include "GameMenu/PlayerZeta.h"

PlayerZeta::PlayerZeta(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:CharactersButton(location, wantedSize)
{
	m_cost = ButtonData::COST_PLAYER_ZETA;
	m_costText.setString(std::to_string(m_cost) + "");

	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayerZeta);
	scaleCharacters(wantedSize);
}

MenuAction PlayerZeta::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayerZeta, m_cost))
		return MenuAction::BuySucceed;

	return MenuAction::None;
}