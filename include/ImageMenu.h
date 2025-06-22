#pragma once
#include "GameObjectType.h"
#include "iostream"
#include <vector>

class ImageMenu {
public:

    static sf::Sprite getSpinte(const GameObjectType& type, const sf::Vector2f& wantedSize);

private:
    static void loadAllTextures();

    static bool m_loaded;

    static std::vector<sf::Texture> m_pictures;

    static void loadStart();
    static void loadStore();
    static void loadHelp();
    static void loadExit();
    static void loadWatch();
    static void loadGitHub();
    static void loadDone();
    static void loadCancel();


    //static void loadSpriteSheet();

};
