//----------------------------------------------------------------------------------------------------
// BaseContext.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include "Engine/Core/StringUtils.hpp"

//----------------------------------------------------------------------------------------------------
class BaseContext
{
public:
    virtual ~BaseContext() = default;
    void    RequestPushState(String const& name);
    String  ConsumeRequestedState();

private:
    String m_requestedState;
};
