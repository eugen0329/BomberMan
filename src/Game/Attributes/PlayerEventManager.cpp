#include "Game/Attributes/PlayerEventManager.hpp"

//PlayerEventManager::PlayerEventManager(Actions & act) : act(&act)
//{
//}

PlayerEventManager::~PlayerEventManager()
{
}

PlayerEventManager::PlayerEventManager() //: act(NULL)
{
}

//void PlayerEventManager::setPlayerActions(Actions & act)
//{
//    this->act = &act;
//}

void PlayerEventManager::handleEvents(const event_t& event)
{
    handleKeyPressedEvents(event);
    handleKeyReleasedEvents(event);
}

//void PlayerEventManager::handleKeyPressedEvents(const event_t& event)
//{
//    if (event.type == sf::Event::KeyPressed) {
//        switch(event.key.code) {
//            case sf::Keyboard::Up :
//                act->move(1.5f);
//                break;
//            case sf::Keyboard::Down :
//                act->move(0.5f);
//                break;
//            case sf::Keyboard::Right :
//                act->move(0.0f);
//                break;
//            case sf::Keyboard::Left :
//                act->move(1.0f);
//                break;
//            case sf::Keyboard::Space :
//                break;
//            default: 
//                ;
//        }
//    }
//}
//
//void PlayerEventManager::handleKeyReleasedEvents(const event_t& event)
//{
//    if (event.type == sf::Event::KeyReleased) {
//        switch(event.key.code) {
//            case sf::Keyboard::Up :
//                act->stop(1.5f); 
//                break;
//            case sf::Keyboard::Down :
//                act->stop(0.5f);
//                break;
//            case sf::Keyboard::Right :
//                act->stop(0.0f);
//                break;
//            case sf::Keyboard::Left :
//                this->stop(1.0f);
//                break;
//            case sf::Keyboard::Space :
//                act->throwBomb("simple");
//                break;
//            default: 
//                ;
//        }
//    }
//}

void PlayerEventManager::handleKeyPressedEvents(const event_t& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Up) {
            this->move(1.5f); 
            //std::cout << "Up" << std::endl;
        } else if(event.key.code == sf::Keyboard::Down) {
            this->move(0.5f);
            //std::cout << "Down" << std::endl;
        } else if(event.key.code == sf::Keyboard::Right) {
            this->move(0.0f);
            //std::cout << "Right" << std::endl;
        } else if(event.key.code == sf::Keyboard::Left) {
            this->move(1.0f);
            //std::cout << "Left" << std::endl;
        } else if(event.key.code == sf::Keyboard::Space) {

            this->throwBomb(std::string("SimpleBomb"));
        }
        
    }
}

void PlayerEventManager::handleKeyReleasedEvents(const event_t& event)
{
    if (event.type == sf::Event::KeyReleased) {
        if(event.key.code == sf::Keyboard::Up) {
            this->stop(1.5f); 
        } else if(event.key.code == sf::Keyboard::Down) {
            this->stop(0.5f);
        } else if(event.key.code == sf::Keyboard::Right) {
            this->stop(0.0f);
        } else if(event.key.code == sf::Keyboard::Left) {
            this->stop(1.0f);
        } else if(event.key.code == sf::Keyboard::Space) {
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
