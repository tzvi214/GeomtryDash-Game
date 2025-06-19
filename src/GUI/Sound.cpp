#include "GUI/Sound.h"

bool Sound::initialize()
{
    if (m_initialized)
        return false;

    /*if (!loadSoundBuffer(SoundType::HitObstacle, "audio/hit_obstacle.wav")) return false;
    if (!loadSoundBuffer(SoundType::Jump, "audio/jump.wav")) return false;
    if (!loadSoundBuffer(SoundType::Explosion, "audio/explosion.wav")) return false;

    m_musicFiles[MusicType::MainMenu] = "audio/main_menu_music.ogg";
    m_musicFiles[MusicType::InGame] = "audio/in_game_music.ogg";*/
    m_initialized = true;
    return true;
}

bool Sound::loadSoundBuffer(SoundType type, const std::string& filename)
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filename))
        return false;

    m_soundBuffers[type] = buffer;
    return true;
}

sf::Sound Sound::getSound(SoundType type)
{
    sf::Sound sound;
    auto it = m_soundBuffers.find(type);
    if (it != m_soundBuffers.end())
        sound.setBuffer(it->second);

    return sound; 
}

sf::Music& Sound::getMusic(MusicType type)
{
    if (type != m_currentMusicType)
    {
        auto it = m_musicFiles.find(type);
        if (it != m_musicFiles.end())
        {
            m_musicPlayer.stop();
            m_musicPlayer.openFromFile(it->second);
            m_currentMusicType = type;
        }
    }
    return m_musicPlayer;
}

Sound::m_initialized = Sound::initialize();