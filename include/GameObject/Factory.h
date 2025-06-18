#pragma once

#include <map>
#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>

#include "GameObject/Object.h"
#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/StaticObject/StaticObject.h"
#include "GameObject/Images/ImagesObject.h"
#include "GameObject/Images/TypeObject.h"

struct ObjectConfig {
    sf::Vector2f location;
    const ImagesObject& images;
    TypeObject playerType;
};

class Factory {
public:
    using CreatorFunc = std::function<std::unique_ptr<Object>(const ObjectConfig&)>;

    static std::unique_ptr<Object> create(char symbol, const ObjectConfig&);
    static bool registerIt(char symbol, CreatorFunc func);

private:
    static std::map<char, CreatorFunc>& getMap();//m_map 
};