#ifndef _ACTOR_HPP_
#define _ACTOR_HPP_

#include <vector>
#include "WorldsObjects/WorldsObject.hpp"

class Actor : public WorldsObject {
private:
public:
    Actor(GameMap &, std::vector<WorldsObject*> &, renderWindow_t &);
    Actor();
    virtual ~Actor();

    virtual void update(float) = 0;
    virtual void draw() = 0;
};

#endif /* end of include guard: _ACTOR_HPP_ */
