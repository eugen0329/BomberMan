#ifndef _ACTOR_HPP_
#define _ACTOR_HPP_

#include <vector>
#include <queue>
#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/Attributes/IAttributes.hpp"


class Actor : public IWorldsObject {
protected:
    enum ActorCommands {
        moveUp,
        moveDown,
        moveRight,
        moveLeft
    };
    std::queue<ActorCommands> commandsQueue;
private:
public:
    Actor(GameMap &, wObjects_t&, window_t&);
    Actor();
    virtual ~Actor();

    virtual void handleCollisions() = 0;
    virtual void checkCollisions() = 0;

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0;
    virtual IAttributes getAttributes() = 0;
};

#endif /* end of include guard: _ACTOR_HPP_ */
