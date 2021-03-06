#include "GlobalEventManager.hpp"

GlobalEventManager::GlobalEventManager()
{
}

GlobalEventManager::GlobalEventManager(window_t & window) : window(&window) 
{
}

GlobalEventManager::~GlobalEventManager()
{
}

void GlobalEventManager::setWindow(window_t & window)
{
    this->window = &window;
}

void GlobalEventManager::handleEvents(const event_t & event)
{
    if(event.type == sf::Event::Closed) {
        window->close();
    }
}
