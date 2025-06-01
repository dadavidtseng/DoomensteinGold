//----------------------------------------------------------------------------------------------------
// GameStack.hpp
//----------------------------------------------------------------------------------------------------

#pragma once
#include "Game/Stack/BaseStack.hpp"


class GameFactory;
class GameContext;

//----------------------------------------------------------------------------------------------------
class GameStack : public BaseStack
{
public:
    GameStack(GameContext* ctx, GameFactory* factory);
};
