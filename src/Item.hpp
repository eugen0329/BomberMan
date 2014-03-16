#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <vector>
#include "WorldsObject.hpp"

class Item : public WorldsObject {
private:
public:
    Item(GameMap&, std::vector<WorldsObject*>&);
    virtual ~Item();

    virtual void changeState() = 0;
    virtual void draw() = 0;

    virtual Vector2D<size_t> getPos(); 
};

#endif /* end of include guard: _ITEM_HPP_ */
