//----------------------------------------------------------------------------------------------------
// Game.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once
#include <vector>

#include "Engine/Math/AABB2.hpp"
#include "Game/Gameplay/GameContext.hpp"
#include "Game/Gameplay/GameFactory.hpp"
#include "Game/Gameplay/GameStack.hpp"
#include "Game/Gameplay/Sound.hpp"

enum class eDeviceType : int8_t;
//----------------------------------------------------------------------------------------------------
class Map;
class Camera;
class Clock;
class PlayerController;

//----------------------------------------------------------------------------------------------------
enum class eGameState : int8_t
{
    NONE,
    ATTRACT,
    LOBBY,
    INGAME
};

//----------------------------------------------------------------------------------------------------
class Game
{
public:
    Game();
    ~Game();

    void Update();
    void Render() const;

    eGameState                     GetGameState() const;
    void                           ChangeState(eGameState nextState);
    PlayerController*              CreateLocalPlayer(int id, eDeviceType deviceType);
    void                           RemoveLocalPlayer(int id); // Remove local player by its unique id and automatically shrink the controller container.
    PlayerController*              GetLocalPlayer(int id) const; // Return the PlayerController with specific controller id.
    PlayerController*              GetControllerByDeviceType(eDeviceType deviceType) const; // Return the first found controller that has the specific device type.
    bool                           GetIsSingleMode() const;
    Clock*                         m_gameClock = nullptr;
    AABB2                          m_screenSpace;
    AABB2                          m_worldSpace;
    Map*                           m_currentMap = nullptr;
    std::vector<PlayerController*> m_localPlayerControllerList;
    SoundPlaybackID m_mainMenuPlaybackID = 0;
    SoundPlaybackID m_inGamePlaybackID   = 0;

private:
    void UpdateFromKeyBoard();
    void UpdateFromController();
    void UpdatePlayerController(float deltaSeconds) const;
    void UpdateListeners(float deltaSeconds) const;
    void RenderAttractMode() const;
    void RenderLobby() const;
    void RenderInGame() const;
    void RenderPlayerController() const;

    void InitializeMaps();

    Camera*           m_screenCamera     = nullptr;
    eGameState        m_currentGameState = eGameState::ATTRACT;
    std::vector<Map*> m_maps;



    GameContext m_gameContext;
    GameFactory m_gameFactory;
    GameStack   m_gameStack = GameStack(nullptr, nullptr);
};
