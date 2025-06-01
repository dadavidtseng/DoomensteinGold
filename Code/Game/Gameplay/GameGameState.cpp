//----------------------------------------------------------------------------------------------------
// GameGameState.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Gameplay/GameGameState.hpp"

#include "Engine/Core/EngineCommon.hpp"
#include "Engine/Core/ErrorWarningAssert.hpp"
#include "Engine/Core/Timer.hpp"
#include "Game/Stack/BaseContext.hpp"


GameGameState::GameGameState()
{
    m_timer = new Timer(5.f, &Clock::GetSystemClock());
}

void GameGameState::OnEnter(BaseContext* ctx)
{
	UNUSED(ctx)
    DebuggerPrintf("[Game.Game] OnEnter\n");
    m_timer->Start();
}

void GameGameState::OnUpdate(float dt, BaseContext* ctx)
{
	UNUSED(dt)
	UNUSED(ctx)
    DebuggerPrintf("[Game.Game] OnUpdate\n");

    if (m_timer->HasPeriodElapsed())
    {
        ctx->RequestPushState("Game.Attract");
    }
    // if (m_elapsedTime >= 3.0f)
    // {
    //     ctx->RequestPushState("MainMenu");
    // }
}

void GameGameState::OnExit(BaseContext* ctx)
{
	
	UNUSED(ctx)
    DebuggerPrintf("[Game.Game] OnExit\n");
}

 char const* GameGameState::GetName() const
{
    return "Game.Game";
}
