#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "Common/BasicTypes.hpp"

#include "StateStack.hpp"
#include "GlobalEventManager.hpp"

#include "Common/StatesID.hpp"
#include "Common/Timer.hpp"
#include "Common/Deferred.hpp"

#include "States/MainMenuState.hpp"
#include "States/GameState.hpp"

class Application {
private:
    typedef std::stack<IDeferred*> DeferredActions;
    typedef struct {
        unsigned int xSize; 
        unsigned int ySize;
        unsigned short int bpp;     // color depth(bits per pixel)
        unsigned short int fps;     // frames per second
        std::string name;
    } windAttr_t;

    windAttr_t windProp;
    window_t window;

    StateStack states;
    GlobalEventManager globalEventManager;
    Timer timer;

    DeferredActions deferred;

    void handleEvents();
    void handleDeferred();
     
public:
    Application();
    ~Application();

    void run();
};

#endif /* end of include guard: _APPLICATION_HPP_ */
