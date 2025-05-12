//----------------------------------------------------------------------------------------------------
// IState.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include "Engine/Core/ErrorWarningAssert.hpp"

class Timer;
//-Forward-Declaration--------------------------------------------------------------------------------
class BaseContext;

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

class GameplayState : public IState
{
public:
 GameplayState();
    void        OnEnter(BaseContext* ctx) override;
    void        OnUpdate(float dt, BaseContext* ctx) override;
    void        OnExit(BaseContext* ctx) override;
    const char* GetName() const override { return "Gameplay"; }

private:
    float m_elapsedTime = 0.f;
};

class MainMenuState : public IState
{
public:
    MainMenuState();
    void        OnEnter(BaseContext* ctx) override;
    void        OnUpdate(float dt, BaseContext* ctx) override;
    void        OnExit(BaseContext* ctx) override;
    const char* GetName() const override { return "MainMenu"; }

private:
    float m_elapsedTime = 0.f;
};
