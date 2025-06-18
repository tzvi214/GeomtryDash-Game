#include "GameObject/Factory.h"


std::map<char, Factory::CreatorFunc>& Factory::getMap() {
    static std::map<char, CreatorFunc> map;
    return map;
}

bool Factory::registerIt(char symbol, CreatorFunc func) {
    getMap()[symbol] = func;
    return true;
}

std::unique_ptr<Object> Factory::create(char symbol, const ObjectConfig& objectConfig) {
    auto it = getMap().find(symbol);
    if (it != getMap().end())
        return it->second(objectConfig);
    return nullptr;
}