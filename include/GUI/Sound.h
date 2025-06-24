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
    MenuSound,
    GameSound
};

class Sound
{
public:
    
    static void playMusic(MusicType type, float valume = 75.f);
private:
    static void playMusic(sf::Music&, float);
    static bool m_loaded;
    static bool initialize();
    static std::map<MusicType, sf::Music> m_musicMap;
    static void closeAllMusic();

};
