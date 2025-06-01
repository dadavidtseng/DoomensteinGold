//----------------------------------------------------------------------------------------------------
// GameGameState.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include "Game/Stack/IState.hpp"

//----------------------------------------------------------------------------------------------------
class GameGameState : public IState
{
public:
    GameGameState();
    void        OnEnter(BaseContext* ctx) override;
    void        OnUpdate(float dt, BaseContext* ctx) override;
    void        OnExit(BaseContext* ctx) override;
    const char* GetName() const override;
};
