#ifndef _ACTIONS_HPP_
#define _ACTIONS_HPP_

#include "WorldsObjects/ObjectProperties.hpp"
#include "Managers/AnimationManager.hpp"

class Actions;
typedef Actions actions_t;

class Actions {
private:
    properties_t * prop;
    AnimationManager * anim;
public:
    Actions(properties_t &, AnimationManager &);
    ~Actions();

    void moveUp(float);
    void moveDown(float);
    void moveRight(float);
    void moveLeft(float);
};



#endif /* end of include guard: _ACTIONS_HPP_ */
