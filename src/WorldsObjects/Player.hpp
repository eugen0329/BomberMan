#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <vector>
#include "WorldsObjects/WorldsObject.hpp"
#include "WorldsObjects/Person.hpp"
#include "WorldsObjects/ObjectProperties.hpp"
#include "Managers/PlayerEventManager.hpp"

#include "SFML/Graphics.hpp"

class Player : public Person {
private:
    friend class PlayerEventManager;


    PlayerEventManager eventManager;
    
    
    properties_t prop;
public:
    Player(GameMap &, std::vector<WorldsObject*> &, renderWindow_t &);
    virtual ~Player();

    void update(event_t &, float);
    void draw();

};

#endif /* end of include guard: _PLAYER_HPP_ */
