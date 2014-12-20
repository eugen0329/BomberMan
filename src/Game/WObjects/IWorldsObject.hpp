#ifndef _IWORLDSOBJECT_HPP_
#define _IWORLDSOBJECT_HPP_

#include <vector>
#include "queue"
#include <string>
#include <cstdio>
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>

#include "Game/Collision.hpp"

#include "Common/Vec2.hpp"
#include "Common/Delegate.hpp"
#include "Game/Map/GameMap.hpp"
#include "Game/Attributes/IAttributes.hpp"

#include "Common/Algorithms.hpp"

class IWorldsObject;

typedef sf::Event event_t;
typedef std::shared_ptr<IWorldsObject> pWObject_t;
typedef std::vector<pWObject_t> wObjects_t;
typedef sf::RenderWindow window_t;

class IWorldsObject {
protected:
    GameMap* map;
    wObjects_t* wObjects;
    window_t * window;
    Delegate destroyingSignal;

public:

    IWorldsObject(GameMap&, wObjects_t &, window_t &);
    IWorldsObject();
    virtual ~IWorldsObject();


    void setMap(GameMap&);
    void setRenderWindow(window_t&);
    virtual void setSignal(Delegate *, std::string) = 0;
    virtual void setWorldObjects(wObjects_t&) = 0;

    virtual void handleCollisions() = 0;
    virtual void addCollision(Collision) = 0;

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0; 

    virtual IAttributes& getAttr() = 0;


};

#endif /* end of include guard: _IWORLDSOBJECT_HPP_ */
