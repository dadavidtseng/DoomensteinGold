//----------------------------------------------------------------------------------------------------
// BaseContext.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/BaseContext.hpp"

BaseContext::~BaseContext()
{
}

void BaseContext::RequestPushState(String const& name)
{
    m_requestedState = name;
}

String BaseContext::ConsumeRequestedState()
{
    String result = m_requestedState;
    m_requestedState.clear();
    return result;
}
