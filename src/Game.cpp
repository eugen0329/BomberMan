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
    //while(states.isNotEmpty()) {
    while(mainWindow.isOpen()) {
        
        eventManager.processEvents(event);
        states.processTopState();
        //states.pop();
        mainWindow.pollEvent(event);
    }
}
