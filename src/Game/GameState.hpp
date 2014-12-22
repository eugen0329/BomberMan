#ifndef _GAMESTATE_HPP_
#define _GAMESTATE_HPP_

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>


#include "Common/Deferred.hpp"
#include "Common/Interfaces/IAppState.hpp"
#include "Game/GameLevel.hpp"

#include "Game/Menu/GameMenuState.hpp"

typedef sf::Event event_t;


class GameState : public IAppState {
private:
    GameLevel* level;
public:
    GameState();
    virtual ~GameState();

    virtual void load(window_t &window, StateStack& st, std::function<void(IDeferred*)>& fn);

    virtual void draw();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);

};

#endif /* end of include guard: _GAMESTATE_HPP_ */
