#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/Attributes/IAttributes.hpp"


class Item : public IWorldsObject {
private:
public:
    Item();
    Item(GameMap&, wObjects_t&, window_t&);
    virtual ~Item() {}

    virtual void handleCollisions() = 0;
    virtual void checkCollisions() = 0;

    virtual void setWorldsObjectsVector(wObjects_t&) = 0;

    virtual void addCollision(Collision) = 0;

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0;
    virtual IAttributes& getAttributes() = 0;
    virtual void setSignal(Delegate*, std::string);
};


#endif /* end of include guard: _ITEM_HPP_ */
