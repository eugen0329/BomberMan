#ifndef _PLAYEREVENTMANAGER_HPP_
#define _PLAYEREVENTMANAGER_HPP_

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

#include "Common/Interfaces/IEventManager.hpp"
#include "Common/Angle.hpp"
#include "Common/Delegate.hpp"

#include "Game/Attributes/PlayerEventHandler.hpp"

#include "Game/Keyset.hpp"



typedef sf::Event event_t;

class PlayerEventManager {
private:
    Keyset * keys;

    Delegate move;
    Delegate stop;
    Delegate throwBomb;
public:
    PlayerEventManager(Keyset);
    virtual ~PlayerEventManager();

    virtual void handleEvents(const event_t&);
    void handleKeyPressedEvents(const event_t&);
    void handleKeyReleasedEvents(const event_t&);

    void setAction(Delegate*, std::string);
};


#endif /* end of include guard: _PLAYEREVENTMANAGER_HPP_ */
