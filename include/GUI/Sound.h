#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include <vector>

enum class SoundType
{
    HitObstacle,
    Jump,
    Explosion,
};

enum class MusicType
{
    MainMenu,
    InGame
};

class Sound
{
public:

   static sf::Sound getSound(SoundType type);
   static sf::Music& getMusic(MusicType type);

private:
    static bool loadSoundBuffer(SoundType type, const std::string& filename);
    static bool loadMusic(MusicType type, const std::string& filename);

    static  std::map<SoundType, sf::SoundBuffer> m_soundBuffers;
    static  std::map<MusicType, std::string> m_musicFiles;
    static  sf::Music m_musicPlayer;
    static  MusicType m_currentMusicType = MusicType::MainMenu;

    static  bool m_initialized = false;

};
