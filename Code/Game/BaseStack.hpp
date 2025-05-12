//----------------------------------------------------------------------------------------------------
// BaseStack.hpp
//----------------------------------------------------------------------------------------------------

#pragma once

#include <stack>

#include "Engine/Core/StringUtils.hpp"
#include "Game/BaseFactory.hpp"
#include "Game/IState.hpp"

//----------------------------------------------------------------------------------------------------
class BaseStack
{
public:
    BaseStack(BaseContext* ctx, BaseFactory* factory);
    virtual ~BaseStack();
    void    Update(float deltaSeconds);
    void    PushState(String const& name);
    void    PopState();

protected:
    BaseContext*        m_context;
    BaseFactory*        m_factory;
    std::stack<IState*> m_stack;
};
