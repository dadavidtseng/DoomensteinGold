//----------------------------------------------------------------------------------------------------
// GameCommon.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/GameCommon.hpp"

#include "Engine/Audio/AudioSystem.hpp"
#include "Engine/Core/EngineCommon.hpp"

//----------------------------------------------------------------------------------------------------
void PlaySoundClicked(char const* keyName)
{
    do
    {
        String const  soundFilePath = g_gameConfigBlackboard.GetValue(keyName, "DEFAULT");
        SoundID const sound         = g_theAudio->CreateOrGetSound(soundFilePath, AudioSystemSoundDimension::Sound2D);
        g_theAudio->StartSound(sound, false, 1.f);
    }
    while (false);
}
