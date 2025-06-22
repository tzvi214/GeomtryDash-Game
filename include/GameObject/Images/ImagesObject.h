#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"
#include "vector"


#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"


class ImagesObject {
public:

    static sf::Sprite getSpriteObject(const TypeObject& type);
    static sf::Sprite getSpritePlayer(const TypeObject& type);

private:
    static void loadAllImagesObject();

    static bool m_loaded;

    static std::vector<sf::Texture> m_imagesObject;

    static void loadImageSpriteSheet();
    static void loadPlayerCharacters();

};