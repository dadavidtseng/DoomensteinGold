//----------------------------------------------------------------------------------------------------
// GameAttractState.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Gameplay/GameAttractState.hpp"

#include "Game.hpp"
#include "GameContext.hpp"
#include "Engine/Core/EngineCommon.hpp"
#include "Engine/Core/ErrorWarningAssert.hpp"
#include "Engine/Core/Timer.hpp"
#include "Engine/Input/InputSystem.hpp"
#include "Game/Framework/App.hpp"
#include "Game/Framework/GameCommon.hpp"
#include "Game/Framework/PlayerController.hpp"
#include "Game/Gameplay/Sound.hpp"
#include "Game/Stack/BaseContext.hpp"

GameAttractState::GameAttractState()
{
    m_timer = new Timer(3.f, &Clock::GetSystemClock());
}

void GameAttractState::OnEnter(BaseContext* ctx)
{
    UNUSED(ctx)
    DebuggerPrintf("[Gameplay] OnEnter\n");
    m_timer->Start();
}

void GameAttractState::OnUpdate(float dt, BaseContext* ctx)
{
    UNUSED(dt)
    UNUSED(ctx)
    DebuggerPrintf("[Game.Attract] OnUpdate\n");

    if (m_timer->HasPeriodElapsed())
    {
        ctx->RequestPushState("Game.Menu");
    }

    // if (g_theInput->WasKeyJustPressed(KEYCODE_ESC))
    // {
    //     App::RequestQuit();
    // }
    //
    // if (g_theInput->WasKeyJustPressed(KEYCODE_SPACE))
    // {
    //     g_theGame->CreateLocalPlayer(0, eDeviceType::KEYBOARD_AND_MOUSE);
    //     g_theGame->ChangeState(eGameState::LOBBY);
    //     PlaySoundClicked("Game.Common.Audio.ButtonClicked");
    //     SoundID mainMenuSoundID = g_theAudio->CreateOrGetSound(g_gameConfigBlackboard.GetValue("Game.Common.Audio.MainMenu", ""), AudioSystemSoundDimension::Sound2D);
    //     g_theGame->m_mainMenuPlaybackID    = g_theAudio->StartSound(mainMenuSoundID, false, 0.25f);
    //
    //     return;
    // }
}

void GameAttractState::OnExit(BaseContext* ctx)
{
    UNUSED(ctx)
    DebuggerPrintf("[Gameplay] OnExit\n");
}

const char* GameAttractState::GetName() const
{
    return "Game.Attract";
}
