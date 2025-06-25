#include "GUI/Sound.h"
#include <stdexcept>

std::map<MusicType, sf::Music> Sound::m_musicMap;
std::map<SoundType, sf::SoundBuffer> Sound::m_soundBuffers;
std::vector<sf::Sound> Sound::m_sounds;
bool Sound::m_loaded = [] { return Sound::initialize(); }();

bool Sound::initialize()
{
    static  bool m_initialized = false;

    if (m_initialized)
        return false;
    // Load music
    if (!m_musicMap[MusicType::MenuSound].openFromFile("MenuSound.mp3"))
        throw std::runtime_error("Failed to load MenuSound.mp3");

    if (!m_musicMap[MusicType::GameSound].openFromFile("GameSound.mp3"))
        throw std::runtime_error("Failed to load GameSound.mp3");
    // Load short sounds
    if (!m_soundBuffers[SoundType::unlock].loadFromFile("unlock.wav"))
        throw std::runtime_error("Failed to load unlock.wav");

    if (!m_soundBuffers[SoundType::touchGift].loadFromFile("touchGift.wav"))
        throw std::runtime_error("Failed to load touchGift.wav");

    if (!m_soundBuffers[SoundType::notification].loadFromFile("notification.wav"))
        throw std::runtime_error("Failed to load notification.wav");

    if (!m_soundBuffers[SoundType::gameOver].loadFromFile("gameOver.wav"))
        throw std::runtime_error("Failed to load gameOver.wav");

    if (!m_soundBuffers[SoundType::finishedLevel].loadFromFile("finishedLevel.wav"))
        throw std::runtime_error("Failed to load finishedLevel.wav");

    if (!m_soundBuffers[SoundType::click].loadFromFile("click.mp3"))
        throw std::runtime_error("Failed to load click.mp3");
   
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

void Sound::playSound(SoundType type, float volume)
{
    auto it = m_soundBuffers.find(type);
    if (it == m_soundBuffers.end())
        throw std::runtime_error("Failed to found sound type");


    m_sounds.erase(
        std::remove_if(m_sounds.begin(), m_sounds.end(),
            [](const sf::Sound& s) { return s.getStatus() == sf::Sound::Stopped; }),
        m_sounds.end());

    for (auto& s : m_sounds)
    {
        if (s.getStatus() != sf::Sound::Playing)
        {
            s.setBuffer(it->second);
            s.setVolume(volume);
            s.play();
            return;
        }
    }

    
  
    if (m_sounds.size() < m_maxSound)
    {
        m_sounds.emplace_back(); 
        m_sounds.back().setBuffer(it->second);
        m_sounds.back().setVolume(volume);
        m_sounds.back().play();
    }
}

