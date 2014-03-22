#include "Managers/PlayerEventManager.hpp"

PlayerEventManager::PlayerEventManager(properties_t & prop) : prop(&prop)
{
}

PlayerEventManager::~PlayerEventManager()
{
}

void PlayerEventManager::processEvents()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
        prop->y += prop->step;
    } 
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        prop->y -= prop->step;
    } 
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        prop->x += prop->step;
    } 
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left )) {
        prop->x -= prop->step;
    }
}
