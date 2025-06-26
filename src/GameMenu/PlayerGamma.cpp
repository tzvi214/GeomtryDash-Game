#include "GameMenu/PlayerGamma.h"

PlayerGamma::PlayerGamma(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:CharactersButton(location, wantedSize)
{
	m_cost = ButtonData::COST_PLAYER_GAMMA;
	m_costText.setString(std::to_string(m_cost));

	m_sprite = ImagesObject::getSpritePlayer(TypeObject::PlayerGamma);
	scaleCharacters(wantedSize);
}

MenuAction PlayerGamma::handleClick(Info& info, sf::RenderWindow& window)
{
	if (info.buyPlayer(TypeObject::PlayerGamma, m_cost))
		return MenuAction::BuySucceed;

	return MenuAction::None;
}
