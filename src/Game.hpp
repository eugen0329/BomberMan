#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "GameStates/GameIsOnState.hpp"
#include "GameStates/StateStack.hpp"
#include "GameStates/StatesID.hpp"

class Game {
private:
    typedef sf::RenderWindow renderWindow_t;

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

     
public:
    Game();
    ~Game();

    void run();
};

#endif /* end of include guard: _GAME_HPP_ */
