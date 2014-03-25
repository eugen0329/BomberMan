#include "Managers/PlayerEventManager.hpp"

PlayerEventManager::PlayerEventManager(actions_t & act) : act(&act)
{
}

PlayerEventManager::~PlayerEventManager()
{
}

void PlayerEventManager::processEvents(float dt)
{

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        act->moveRight(dt);
    } 
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left )) {
        act->moveLeft(dt);
    }
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
        act->moveDown(dt);
    } 
    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        act->moveUp(dt);
    }     
}
