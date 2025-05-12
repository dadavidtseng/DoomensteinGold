//----------------------------------------------------------------------------------------------------
// IState.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/IState.hpp"

#include "BaseContext.hpp"
#include "Engine/Core/Timer.hpp"

GameplayState::GameplayState()
{
    m_timer = new Timer(3.f, &Clock::GetSystemClock());
}

void GameplayState::OnEnter(BaseContext* ctx)
{
    DebuggerPrintf("[Gameplay] OnEnter\n");
    m_timer->Start();
}

void GameplayState::OnUpdate(float dt, BaseContext* ctx)
{
    DebuggerPrintf("[Gameplay] OnUpdate\n");
    m_elapsedTime += dt;
    if (m_timer->HasPeriodElapsed())
    {
        ctx->RequestPushState("MainMenu");
    }
    // if (m_elapsedTime >= 3.0f)
    // {
    //     ctx->RequestPushState("MainMenu");
    // }
}

void GameplayState::OnExit(BaseContext* ctx)
{
    DebuggerPrintf("[Gameplay] OnExit\n");
}

MainMenuState::MainMenuState()
{
    m_timer = new Timer(1.f, &Clock::GetSystemClock());
}

void MainMenuState::OnEnter(BaseContext* ctx)
{
    DebuggerPrintf("[MainMenu] OnEnter\n");
    m_timer->Start();
}

void MainMenuState::OnUpdate(float dt, BaseContext* ctx)
{
    DebuggerPrintf("[MainMenu] OnUpdate\n");
    m_elapsedTime += dt;
    if (m_timer->HasPeriodElapsed())
    {
        ctx->RequestPushState("Gameplay");
    }
    // if (m_elapsedTime >= 3.0f)
    // {
    //     ctx->RequestPushState("Gameplay");
    // }
}

void MainMenuState::OnExit(BaseContext* ctx)
{
    DebuggerPrintf("[MainMenu] OnExit\n");
}
