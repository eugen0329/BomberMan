#ifndef _PLAYEREVENTMANAGER_HPP_
#define _PLAYEREVENTMANAGER_HPP_

#include "Managers/EventManager.hpp"
#include "WorldsObjects/ObjectProperties.hpp"
#include "SFML/System.hpp"

#include <iostream>

class PlayerEventManager {
private:
    properties_t* prop;
public:
    PlayerEventManager(properties_t &);
    virtual ~PlayerEventManager();
    //void setPlayer();

    virtual void processEvents();
};


#endif /* end of include guard: _PLAYEREVENTMANAGER_HPP_ */
