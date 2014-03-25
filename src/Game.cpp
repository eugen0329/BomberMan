#include "Game.hpp"

Game::Game() 
{
    windProp.xSize = 640;
    windProp.ySize = 480;
    windProp.bpp   = 32;
    windProp.name  = "\\o";
    windProp.fps   = 60;
    
    //sf::VideoMode mode(windProp.xSize, windProp.ySize, windProp.bpp);
    sf::VideoMode mode(windProp.xSize, windProp.ySize);

    mainWindow.create(mode, windProp.name);
    mainWindow.setFramerateLimit(windProp.fps);
    mainWindow.clear(sf::Color::White);
    
    eventManager.setRenderWindow(mainWindow);

    states.setRenderWindow(&mainWindow);
    states.push(new GameIsOnState);


}

Game::~Game()
{
    states.clearStack();
    if(mainWindow.isOpen()) {
        mainWindow.close();
    }
}

void Game::run()
{
    while(mainWindow.isOpen()) {
        event_t event;
        while(mainWindow.pollEvent(event)) {
            eventManager.processEvents(event);            
        }
        states.top()->processState(timer.getElapsedTime());
    }
}
