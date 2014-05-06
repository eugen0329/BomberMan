#include "Game/Attributes/PlayerEventManager.hpp"

PlayerEventManager::PlayerEventManager(Keyset::SetID setID)
{
    keys = new Keyset(setID);
    //keys = new Keyset(Keyset::NUM8564Right);
}
PlayerEventManager::~PlayerEventManager()
{
}

void PlayerEventManager::handleEvents(const event_t& event)
{
    handleKeyPressedEvents(event);
    handleKeyReleasedEvents(event);
}

void PlayerEventManager::handleKeyPressedEvents(const event_t& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if(event.key.code == keys->up) {
            this->move(1.5f); 
        } else if(event.key.code == keys->down) {
            this->move(0.5f);
        } else if(event.key.code == keys->right) {
            this->move(0.0f);
        } else if(event.key.code == keys->left) {
            this->move(1.0f);
        } else if(event.key.code == keys->space) {
            this->throwBomb(std::string("SimpleBomb"));
        }
        
    }
}

void PlayerEventManager::handleKeyReleasedEvents(const event_t& event)
{
    if (event.type == sf::Event::KeyReleased) {
        if(event.key.code == keys->up) {
            this->stop(1.5f); 
        } else if(event.key.code == keys->down) {
            this->stop(0.5f);
        } else if(event.key.code == keys->right) {
            this->stop(0.0f);
        } else if(event.key.code == keys->left) {
            this->stop(1.0f);
        } else if(event.key.code == keys->space) {
        }
    }
}

void PlayerEventManager::setAction(Delegate* delegate, std::string signalName)
{
    if(signalName == "throwBomb") {
        this->throwBomb = *delegate;
    } else if ( signalName == "move" ) {
        this->move = *delegate;
    } else if ( signalName == "stop" ) {
        this->stop = *delegate;
    } 
}
