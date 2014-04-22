#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "Game/GameState.hpp"
#include "Application/StateStack.hpp"
#include "Common/StatesID.hpp"
#include "Application/GlobalEventManager.hpp"
#include "Common/Timer.hpp"

class Application {
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
    renderWindow_t window;

    StateStack states;
    GlobalEventManager globalEventManager;
    Timer timer;

    void handleEvents();
     
public:
    Application();
    ~Application();

    void run();
};

#endif /* end of include guard: _APPLICATION_HPP_ */
