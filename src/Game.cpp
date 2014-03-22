#include "Game.hpp"

Game::Game() 
{
    windProp.xSize = 800;
    windProp.ySize = 600;
    windProp.bpp   = 32;
    windProp.name  = "\\o";
    windProp.fps   = 60;
    
    sf::VideoMode mode(windProp.xSize, windProp.ySize, windProp.bpp);

    mainWindow.create(mode, windProp.name);
    mainWindow.setFramerateLimit(windProp.fps);
    
    eventManager.setRenderWindow(mainWindow);

    states.setRenderWindow(&mainWindow);
    states.push(new GameIsOnState);


}

Game::~Game()
{
    mainWindow.close();
}

void Game::run()
{
    event_t event;
    while(mainWindow.isOpen()) {
        mainWindow.pollEvent(event);

        eventManager.processEvents(event);
        states.top()->processState(timer.getElapsedTime());
    }
}
