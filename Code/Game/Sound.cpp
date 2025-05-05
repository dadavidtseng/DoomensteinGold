//----------------------------------------------------------------------------------------------------
// Sound.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Sound.hpp"

#include "Game/GameCommon.hpp"

//----------------------------------------------------------------------------------------------------
Sound::Sound(XmlElement const& element)
{
    m_name     = ParseXmlAttribute(element, "sound", m_name);
    m_filePath = ParseXmlAttribute(element, "name", m_filePath);
    m_id       = g_theAudio->CreateOrGetSound(m_filePath, AudioSystemSoundDimension::Sound3D);
}

//----------------------------------------------------------------------------------------------------
SoundID Sound::GetSoundID() const
{
    return m_id;
}
