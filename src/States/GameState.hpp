#ifndef _GAMESTATE_HPP_
#define _GAMESTATE_HPP_

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "StateStack.hpp"
#include "Common/BasicTypes.hpp"
#include "States/IAppState.hpp"
#include "Game/GameLevel.hpp"

#include "States/GameMenuState.hpp"
#include "States/GameOverState.hpp"

class GameState : public IAppState {
private:
    GameLevel* level;
public:
    GameState();
    virtual ~GameState();
    virtual void draw();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void setWindow(window_t& window);
};

#endif /* end of include guard: _GAMESTATE_HPP_ */
