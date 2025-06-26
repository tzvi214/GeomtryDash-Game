
#include "GameObject/Images/ImagesObject.h"

std::vector<sf::Texture> ImagesObject::m_imagesObject;
bool ImagesObject::m_loaded = [] {  ImagesObject::loadAllImagesObject(); return true; }();

void ImagesObject::loadAllImagesObject()
{

    static bool loaded = false;
    if (loaded)
        return;

    m_imagesObject.resize(static_cast<int>(TypeObject::count));
    loadImageSpriteSheet();
    loadPlayerCharacters();
    loadLock();

    loaded = true;
}


void ImagesObject::loadImageSpriteSheet()
{
    if (!m_imagesObject[static_cast<int>(TypeObject::SpriteSheet)].loadFromFile("GeometryDashSpriteSheet.png"))
        std::cout << "Error: \n    Failed to load GeometryDashSpriteSheet image (file not found).";

}

void ImagesObject::loadPlayerCharacters()
{
    if (!m_imagesObject[static_cast<int>(TypeObject::PlayerCharacters)].loadFromFile("PlayerCharacters.png"))
        std::cout << "Error: \n    Failed to load Player Characters image (file not found).";
}

void ImagesObject::loadLock()
{
    if (!m_imagesObject[static_cast<int>(TypeObject::lock)].loadFromFile("Lock.png"))
        std::cout << "Error: \n    Failed to load Lock image (file not found).";
}



sf::Sprite ImagesObject::getSpriteObject(const TypeObject& type)
{

    sf::Sprite sprite;
    sprite.setTexture(m_imagesObject[static_cast<int>(TypeObject::SpriteSheet)]);


    switch (type)
    {

    case TypeObject::Enemy:
        sprite.setTextureRect(sf::IntRect(100, 584, 50, 50));
        break;

    case TypeObject::Obstacle:
        sprite.setTextureRect(sf::IntRect(440, 430, 50, 50));
        break;

    case TypeObject::player:
        sprite.setTextureRect(sf::IntRect(639, 710, 50, 50));
        break;

    case TypeObject::PlayeraAlpha:
        sprite.setTextureRect(sf::IntRect(490, 660, 32, 32));
        break;

    case TypeObject::Platform:
        sprite.setTextureRect(sf::IntRect(682, 513, 50, 50));
        break;

    case TypeObject::ExitDoor:
        sprite.setTextureRect(sf::IntRect(40, 836, 80, 80));
        break;

    case TypeObject::Gift:
        sprite.setTextureRect(sf::IntRect(879, 173, 50, 50));
        break;

    default:
        return sf::Sprite();
    }

    return sprite;
}


sf::Sprite ImagesObject::getSpritePlayer(const TypeObject& type)
{
    sf::Sprite sprite;
    sprite.setTexture(m_imagesObject[static_cast<int>(TypeObject::PlayerCharacters)]);

    switch (type)
    {

    case TypeObject::player:
        sprite.setTextureRect(sf::IntRect(269, 197, 295, 295)); // deffult Player
        sprite.setScale(50.f / 295.f, 50.f / 295.f);
        break;

    case TypeObject::PlayeraAlpha:
        sprite.setTextureRect(sf::IntRect(269, 197, 295, 295));
        sprite.setScale(50.f / 295.f, 50.f / 295.f);
        break;

    case TypeObject::PlayeraBeta:
        sprite.setTextureRect(sf::IntRect(603, 194, 300, 300));
        sprite.setScale(50.f / 300.f, 50.f / 300.f);
        break;


    case TypeObject::PlayerGamma:
        sprite.setTextureRect(sf::IntRect(603, 544, 300, 300));
        sprite.setScale(50.f / 300.f, 50.f / 300.f);
        break;

    case TypeObject::PlayerDelta:
        sprite.setTextureRect(sf::IntRect(268, 544, 300, 300));
        sprite.setScale(50.f / 300.f, 50.f / 300.f);
        break;

    case TypeObject::PlayerEpsilon:
        sprite.setTextureRect(sf::IntRect(941, 544, 293, 300));
        sprite.setScale(50.f / 293.f, 50.f / 300.f);
        break;

    case TypeObject::PlayerZeta:
        sprite.setTextureRect(sf::IntRect(939, 146, 300, 346));
        sprite.setScale(50.f / 300.f, 50.f / 346.f);
        break;

    default:
        return sf::Sprite();
    }

    return sprite;
}


sf::Sprite ImagesObject::getSpritLock(const sf::Vector2f& wantedSize)
{
    sf::Sprite sprite;
    sprite.setTexture(m_imagesObject[static_cast<int>(TypeObject::lock)]);

    sf::Texture& texture = m_imagesObject[static_cast<int>(TypeObject::lock)];
    sf::Vector2u texSize = texture.getSize();

    float scaleX = wantedSize.x / texSize.x;
    float scaleY = wantedSize.y / texSize.y;

    sprite.setScale(scaleX, scaleY);
    sprite.setColor(sf::Color(255, 255, 255, 191)); //  75%

    return sprite;
}
