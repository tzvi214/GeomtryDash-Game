#include "GUI/Sound.h"

//sf::Music& Sound::getMusic(MusicType type)
//{
//    
//}

bool Sound::initialize()
{
    static  bool m_initialized = false;

    if (m_initialized)
        return false;

    /*if (!loadSoundBuffer(SoundType::HitObstacle, "audio/hit_obstacle.wav")) 
        return false;
    if (!loadSoundBuffer(SoundType::Jump, "audio/jump.wav"))    
        return false;
    if (!loadSoundBuffer(SoundType::Explosion, "audio/explosion.wav"))  
        return false;*/

 /*   m_musicFiles[MusicType::MainMenu] = "audio/main_menu_music.ogg";
    m_musicFiles[MusicType::InGame] = "audio/in_game_music.ogg";*/
   // m_musicFiles[MusicType::GameSound] = "GameSound.mp3";
   
    m_initialized = true;
    return true;
}
bool Sound::m_loaded = [] { return Sound::initialize(); }();

