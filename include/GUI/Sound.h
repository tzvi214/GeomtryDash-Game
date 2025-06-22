#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include <string>

enum class SoundType// sort sound
{
    HitObstacle,
    Jump,
    Explosion
};

enum class MusicType// long sound 
{
    MainMenu,
    InGame,
    GameSound
};

class Sound
{
public:
    
    static sf::Music& getMusic(MusicType type);

private:
    static bool m_loaded;
    static bool initialize();
  //  static std::map<MusicType,  sf::Music> m_music;
    static sf::Music m_gameSound;

};
