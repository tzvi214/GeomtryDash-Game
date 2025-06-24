#include "GUI/Sound.h"
#include <stdexcept>
std::map<MusicType, sf::Music> Sound::m_musicMap;


bool Sound::m_loaded = [] { return Sound::initialize(); }();

bool Sound::initialize()
{
    static  bool m_initialized = false;

    if (m_initialized)
        return false;
    
    if (!m_musicMap[MusicType::MenuSound].openFromFile("MenuSound.mp3"))
        throw std::runtime_error("Failed to load MenuSound.mp3");

    if (!m_musicMap[MusicType::GameSound].openFromFile("GameSound.mp3"))
        throw std::runtime_error("Failed to load GameSound.mp3");

    m_initialized = true;
    return true;
}

void Sound::closeAllMusic()
{
    for (auto& [type, music] : m_musicMap)
    {
        if (music.getStatus() == sf::Music::Playing)
            music.stop();
    }
}

void Sound::playMusic(MusicType type, float valume)
{  
    closeAllMusic();
  
   auto it = m_musicMap.find(type);
   if (it == m_musicMap.end())
       throw std::runtime_error("Failed to found music type");

   playMusic(it->second, valume);
}

void Sound::playMusic(sf::Music& music, float valume)
{
    music.setLoop(true);
    music.setVolume(valume);
    music.play();
}
