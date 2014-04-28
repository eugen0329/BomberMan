#include "Application/Application.hpp"

Application::Application() 
{
    windProp.xSize = 640;
    windProp.ySize = 480;
    windProp.bpp   = 32;
    windProp.name  = "\\o";
    windProp.fps   = 60;
    
    //sf::VideoMode mode(windProp.xSize, windProp.ySize, windProp.bpp);
    sf::VideoMode mode(windProp.xSize, windProp.ySize);

    window.create(mode, windProp.name);
    window.setFramerateLimit(windProp.fps);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.clear(sf::Color::White);
    
    globalEventManager.setRenderWindow(window);

    states.setRenderWindow(window);
    states.push(new GameState);
}

Application::~Application()
{
    states.clearStack();
    if(window.isOpen()) {
        window.close();
    }
}

void Application::run()
{
    sf::Clock clock;
    while(window.isOpen()) {

        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / currentTime;
        if(fps < 55) std::cout << "fps: " << fps << std::endl;

        handleEvents();
        states.top()->update(timer.getElapsedTime());
        states.top()->draw();
        states.top()->display(); 
    }
}

void Application::handleEvents()
{
    static event_t event;
    while(window.pollEvent(event)) { 
        globalEventManager.handleEvents(event);            
        states.top()->handleEvents(event);
    }
}
