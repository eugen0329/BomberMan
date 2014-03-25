#ifndef _PLAYEREVENTMANAGER_HPP_
#define _PLAYEREVENTMANAGER_HPP_

#include "Managers/EventManager.hpp"
#include "WorldsObjects/Actions.hpp"
#include "SFML/System.hpp"

#include <iostream>

class PlayerEventManager {
private:
    actions_t* act;
public:
    PlayerEventManager(actions_t &);
    virtual ~PlayerEventManager();
    //void setPlayer();

    virtual void processEvents(float);
};


#endif /* end of include guard: _PLAYEREVENTMANAGER_HPP_ */
