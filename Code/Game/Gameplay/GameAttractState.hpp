//----------------------------------------------------------------------------------------------------
// GameAttractState.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include "Game/Stack/IState.hpp"

//----------------------------------------------------------------------------------------------------
class GameAttractState : public IState
{
public:
    GameAttractState();
    void        OnEnter(BaseContext* ctx) override;
    void        OnUpdate(float dt, BaseContext* ctx) override;
    void        OnExit(BaseContext* ctx) override;
    const char* GetName() const override;
};
