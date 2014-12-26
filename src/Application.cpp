#include "Application.hpp"


Application::Application() 
{
    windProp.xSize = 640;
    windProp.ySize = 480;
    windProp.bpp   = 32;
    windProp.name  = "BomberMan";
    windProp.fps   = 60;
    
    sf::VideoMode mode(windProp.xSize, windProp.ySize);

    window.create(mode, windProp.name, sf::Style::Titlebar);
    window.setFramerateLimit(windProp.fps);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.clear(sf::Color::White);
    
    globalEventManager.setWindow(window);

    states.push = [&](IAppStatePtr newState) {
        newState->setWindow(window);
        newState->setPushDeferredFn([&](deferred_t newDeferred) {
            deferred.push(newDeferred);
        });
        states.stack.push(newState);
    };

    states.push(IAppStatePtr(new MainMenuState));
}

Application::~Application()
{
    states.clear();
    if(window.isOpen()) window.close();
    while(! deferred.empty()) deferred.pop();
}

void Application::run()
{
    while(window.isOpen()) {
        handleEvents();

        states.top()->update(timer.getElapsedTime());
        states.top()->draw();
        states.top()->display(); 

        handleDeferred();       

        float fps = timer.getFPS();
        if(fps < 55) std::cerr << "fps: " << fps << "\n";
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

void Application::handleDeferred()
{
    while(! deferred.empty()) {
        deferred.top()(&states);
        deferred.pop();
    }
}
