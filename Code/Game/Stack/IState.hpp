//----------------------------------------------------------------------------------------------------
// IState.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once

//-Forward-Declaration--------------------------------------------------------------------------------
class BaseContext;
class Timer;

//----------------------------------------------------------------------------------------------------
class IState
{
public:
    virtual             ~IState() = default;
    virtual void        OnEnter(BaseContext* ctx) = 0;
    virtual void        OnUpdate(float dt, BaseContext* ctx) = 0;
    virtual void        OnExit(BaseContext* ctx) = 0;
    virtual const char* GetName() const = 0;
    Timer* m_timer = nullptr;
};