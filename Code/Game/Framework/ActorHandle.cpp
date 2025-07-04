//----------------------------------------------------------------------------------------------------
// ActorHandle.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Framework/ActorHandle.hpp"

//----------------------------------------------------------------------------------------------------
ActorHandle const ActorHandle::INVALID = ActorHandle(0x0000ffff, 0x0000ffff);

//----------------------------------------------------------------------------------------------------
ActorHandle::ActorHandle()
    : m_data(INVALID.m_data)
{
}

//----------------------------------------------------------------------------------------------------
ActorHandle::ActorHandle(unsigned int const uid,
                         unsigned int const index)
{
    m_data = (uid << 16) | (index & 0x0000ffff);
}

//----------------------------------------------------------------------------------------------------
bool ActorHandle::IsValid() const
{
    return *this != INVALID;
}

//----------------------------------------------------------------------------------------------------
unsigned int ActorHandle::GetIndex() const
{
    return m_data & 0x0000ffff;
}

//----------------------------------------------------------------------------------------------------
bool ActorHandle::operator==(ActorHandle const& other) const
{
    return m_data == other.m_data;
}

//----------------------------------------------------------------------------------------------------
bool ActorHandle::operator!=(ActorHandle const& other) const
{
    return m_data != other.m_data;
}
