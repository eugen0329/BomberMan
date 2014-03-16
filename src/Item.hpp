#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include "WorldsObject.hpp"

class Item : public WorldsObject {
private:
public:
    Item(GameMap&, std::vector<WorldsObject*> &);
    virtual ~Item();

    virtual void changeState();
    virtual void draw();

    virtual Vector2D<size_t> getPos(); 
};

#endif /* end of include guard: _ITEM_HPP_ */
