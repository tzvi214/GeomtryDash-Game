#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include <string>

enum class SoundType// sort sound
{
   click,
   finishedLevel,
   gameOver,
   notification,
   touchGift,
   unlock
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
    static void playSound(SoundType type, float volume = 75.f);
private:
    static bool m_loaded;
    static bool initialize();
     //-- music ---
    static void playMusic(sf::Music&, float);
    static std::map<MusicType, sf::Music> m_musicMap;
    static void closeAllMusic();
    // --- sound ---
    static std::map<SoundType, sf::SoundBuffer> m_soundBuffers;
    static std::vector<sf::Sound> m_sounds;
    static const  int m_maxSound = 20;

};
