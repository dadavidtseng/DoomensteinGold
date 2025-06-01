//----------------------------------------------------------------------------------------------------
// GameMenuState.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Gameplay/GameMenuState.hpp"

#include "Engine/Core/ErrorWarningAssert.hpp"
#include "Engine/Core/Timer.hpp"
#include "Game/Stack/BaseContext.hpp"
#include <Engine/Core/EngineCommon.hpp>

GameMenuState::GameMenuState()
{
    m_timer = new Timer(3.f, &Clock::GetSystemClock());
}

void GameMenuState::OnEnter(BaseContext* ctx)
{
    UNUSED(ctx)
    DebuggerPrintf("[Game.Menu] OnEnter\n");
    m_timer->Start();
}

void GameMenuState::OnUpdate(float dt, BaseContext* ctx)
{
    UNUSED(dt)
    UNUSED(ctx)
    DebuggerPrintf("[Game.Menu] OnUpdate\n");

    if (m_timer->HasPeriodElapsed())
    {
        ctx->RequestPushState("Game.Game");
    }
    // if (m_elapsedTime >= 3.0f)
    // {
    //     ctx->RequestPushState("MainMenu");
    // }
}

void GameMenuState::OnExit(BaseContext* ctx)
{
    UNUSED(ctx)
    DebuggerPrintf("[Game.Menu] OnExit\n");
}

const char* GameMenuState::GetName() const
{
    return "Game.Menu";
}
