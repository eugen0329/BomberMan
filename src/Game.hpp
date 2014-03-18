#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "GameStage.hpp"

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

    std::vector<GameStage> stages;
    windowProperties_t windProp;
    renderWindow_t mainWindow;

     
public:
    Game();
    ~Game();
};

#endif /* end of include guard: _GAME_HPP_ */
