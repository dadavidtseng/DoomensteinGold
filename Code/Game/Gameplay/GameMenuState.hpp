//----------------------------------------------------------------------------------------------------
// GameMenuState.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include "Game/Stack/IState.hpp"

//----------------------------------------------------------------------------------------------------
class GameMenuState : public IState
{
public:
    GameMenuState();
    void        OnEnter(BaseContext* ctx) override;
    void        OnUpdate(float dt, BaseContext* ctx) override;
    void        OnExit(BaseContext* ctx) override;
    const char* GetName() const override;
};
