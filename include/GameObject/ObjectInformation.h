#pragma once  
#include <SFML/Graphics.hpp>  

class ObjectInformation
{
public:
    void draw(sf::RenderWindow& window, int level)const;

    void setNextLevel(bool nextLevel) { m_nextLevel = nextLevel; }
    void setPlayerDead(bool playerDead) { m_PlayerDead = playerDead; }
    void addCoins(int coins) { m_coins += coins; }

    bool isNextLevel() const { return m_nextLevel; }
    bool isPlayerDead() const { return m_PlayerDead; }
    int getCoins() const { return m_coins; }
    int moveCoins()
    {
        int coins = m_coins;
        m_coins = 0;
        return coins;
    }

private:
    bool m_nextLevel = false;
    bool m_PlayerDead = false;   
    int m_coins = 0;
};
