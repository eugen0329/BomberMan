#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <vector>
#include "WorldsObjects/WorldsObject.hpp"
#include "WorldsObjects/Actor.hpp"
#include "WorldsObjects/ObjectProperties.hpp"
#include "Managers/PlayerEventManager.hpp"
#include "Managers/AnimationManager.hpp"

#include "SFML/Graphics.hpp"

class Player : public Actor {
private:
    // ObjectProperties {
    //Vector2D<size_t> pos;
    //size_t step;

    //texture_t texture;
    //sprite_t sprite;
    // }

    properties_t prop;
  

    AnimationManager animationManager;
    actions_t act;
    PlayerEventManager eventManager;

    void checkForCollisions();
    
public:
    Player(GameMap &, std::vector<WorldsObject*> &, renderWindow_t &);
    virtual ~Player();

    void update(float);
    void draw();

};

#endif /* end of include guard: _PLAYER_HPP_ */
