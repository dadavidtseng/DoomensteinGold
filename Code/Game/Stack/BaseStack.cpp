//----------------------------------------------------------------------------------------------------
// BaseStack.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Stack/BaseStack.hpp"

#include "Game/Stack/BaseContext.hpp"
#include "Game/Stack/BaseFactory.hpp"
#include "Game/Stack/IState.hpp"

//----------------------------------------------------------------------------------------------------
BaseStack::BaseStack(BaseContext* ctx,
                     BaseFactory* factory)
    : m_context(ctx),
      m_factory(factory)
{
}

//----------------------------------------------------------------------------------------------------
BaseStack::~BaseStack()
{
    while (!m_stack.empty())
    {
        delete m_stack.top();
        m_stack.pop();
    }
}

//----------------------------------------------------------------------------------------------------
void BaseStack::Update(float const deltaSeconds)
{
    if (!m_stack.empty())
    {
        m_stack.top()->OnUpdate(deltaSeconds, m_context);
    }

    // 檢查是否有新的推入狀態請求
    String requested = m_context->ConsumeRequestedState();
    if (!requested.empty())
    {
        PushState(requested);
    }
}

//----------------------------------------------------------------------------------------------------
void BaseStack::PushState(String const& name)
{
    if (IState* state = m_factory->Create(name))
    {
        if (!m_stack.empty())
        {
            m_stack.top()->OnExit(m_context);
        }
        m_stack.push(state);
        m_stack.top()->OnEnter(m_context);
    }
}

//----------------------------------------------------------------------------------------------------
void BaseStack::PopState()
{
    if (!m_stack.empty())
    {
        m_stack.top()->OnExit(m_context);
        delete m_stack.top();
        m_stack.pop();
    }
    if (!m_stack.empty())
    {
        m_stack.top()->OnEnter(m_context);
    }
}
