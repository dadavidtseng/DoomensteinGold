//----------------------------------------------------------------------------------------------------
// GameStack.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/Gameplay/GameStack.hpp"

#include "GameContext.hpp"
#include "GameFactory.hpp"

GameStack::GameStack(GameContext* ctx, GameFactory* factory)
    : BaseStack(ctx, factory)
{
}
