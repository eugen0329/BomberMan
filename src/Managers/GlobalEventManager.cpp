#include "Managers/GlobalEventManager.hpp"

GlobalEventManager::GlobalEventManager()
{
}

GlobalEventManager::GlobalEventManager(renderWindow_t & renderWindow) : pRendeWindow(&renderWindow) 
{
}

GlobalEventManager::~GlobalEventManager()
{
}

void GlobalEventManager::setRenderWindow(renderWindow_t & renderWindow) 
{
    this->pRendeWindow = &renderWindow;
}

void GlobalEventManager::processEvents(event_t & event)
{
    if(event.type == sf::Event::Closed) {
        pRendeWindow->close();
    }
}
