#include "Application/Application.hpp"

Application::Application() 
{
    windProp.xSize = 640;
    windProp.ySize = 480;
    windProp.bpp   = 32;
    windProp.name  = "\\o";
    windProp.fps   = 60;
    
    
    sf::VideoMode mode(windProp.xSize, windProp.ySize);

    window.create(mode, windProp.name, sf::Style::Titlebar);
    window.setFramerateLimit(windProp.fps);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);
    window.clear(sf::Color::White);
    
    globalEventManager.setRenderWindow(window);

    //auto a = std::bind(&Application::pushDeferred, *this); [&](IDeferred* newDeferred) { deferred.push(newDeferred);};
    states.load(window, [&](IDeferred* newDeferred) { deferred.push(newDeferred);} );

   // auto a = new Deferred<void>([](){std::cout <<1;});

    //std::function<void(IDeferred*)> fn = [&](IDeferred* newDeferred) { deferred.push(newDeferred);};
    states.push(new MainMenuState);
    //deferred.push(new Deferred<void>(&MainMenuState::changeToGame, &states));
    
    //states.push(new MainMenuState( std::bind(&Application::pushDeferred, *this) ));
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

    while(window.isOpen()) {
        handleEvents();
        states.top()->update(timer.getElapsedTime());
        states.top()->draw();
        states.top()->display(); 

        handleDeferred();       

        float fps = timer.getFPS();
        if(fps < 55) std::cerr << "fps: " << fps << std::endl;
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
        std::cout << "\nhandle\n";
        deferred.top()->call();
        deferred.pop();
    }
}
