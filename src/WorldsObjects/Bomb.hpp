#ifndef _BOMB_HPP_
#define _BOMB_HPP_

#include <vector>
#include "WorldsObjects/WorldsObject.hpp"
#include "WorldsObjects/Item.hpp"

class Bomb : public Item {
private:
public:
    Bomb(GameMap&, std::vector<WorldsObject*> &);
    virtual ~Bomb();

    virtual void changeState();
    virtual void draw();
};

#endif /* end of include guard: _BOMB_HPP_ */
