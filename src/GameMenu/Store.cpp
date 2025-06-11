﻿#include "GameMenu/Store.h"

Store::Store(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Button(GameObjectType::Store, location, wantedSize)
{
}

void Store::handleClick(State & state, sf::RenderWindow& window, sf::Event& event)
{
	state.setStore(true);
	// פה יהיה פתיחה של החנות וכדומה
	m_gameStore.runStore(window, state, event /*,info*/);
}
