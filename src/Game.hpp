#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "GameStates/GameIsOnState.hpp"
#include "StateStack.hpp"
#include "GameStates/StatesID.hpp"
#include "Managers/GlobalEventManager.hpp"
#include "Timer.hpp"

class Game {
private:
    typedef sf::RenderWindow renderWindow_t;
    typedef sf::Event event_t;

    typedef struct {
        unsigned int xSize;
        unsigned int ySize;
        unsigned short int bpp;     // color depth(bits per pixel)
        unsigned short int fps;     // frames per second
        std::string name;
    } windowProperties_t;

    windowProperties_t windProp;
    renderWindow_t mainWindow;

    StateStack states;
    GlobalEventManager eventManager;
    Timer timer;

     
public:
    Game();
    ~Game();

    void run();
};

#endif /* end of include guard: _GAME_HPP_ */
