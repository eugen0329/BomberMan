#include "Managers/PlayerEventManager.hpp"

PlayerEventManager::PlayerEventManager(actions_t & act) : act(&act)
{
}

PlayerEventManager::~PlayerEventManager()
{
}

void PlayerEventManager::processEvents()
{
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
        act->moveDown();
    } 
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        act->moveUp();
    } 
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        act->moveRight();
    } 
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left )) {
        act->moveLeft();
    }
}
