#include "GUI/Sound.h"
#include <stdexcept>

sf::Music Sound::m_gameSound;
bool Sound::m_loaded = [] { return Sound::initialize(); }();

bool Sound::initialize()
{
    static  bool m_initialized = false;

    if (m_initialized)
        return false;
    if (!m_gameSound.openFromFile("GameSound1.mp3"))
    {
        throw std::runtime_error("Failed to load GameSound.mp3");
    }
    
    m_initialized = true;
    return true;
}

sf::Music& Sound::getMusic(MusicType type)
{
    if (type == MusicType::GameSound) {
        
		return m_gameSound;
    }
    throw std::runtime_error("Failed to found music type ");

}
