#ifndef _ACTIONS_HPP_
#define _ACTIONS_HPP_

#include "WorldsObjects/ObjectProperties.hpp"

class Actions;
typedef Actions actions_t;

class Actions {
private:
    properties_t * prop;
public:
    Actions(properties_t & prop);
    ~Actions();

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};



#endif /* end of include guard: _ACTIONS_HPP_ */
