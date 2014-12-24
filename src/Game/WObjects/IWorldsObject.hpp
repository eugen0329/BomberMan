#ifndef _IWORLDSOBJECT_HPP_
#define _IWORLDSOBJECT_HPP_

#include <vector>
#include <string>
#include <cstdio>
#include <memory>
#include <functional>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>

#include "Common/Algorithms.hpp"
#include "Common/Vec2.hpp"
#include "Common/Delegate.hpp"
#include "Game/Map/GameMap.hpp"



class IWorldsObject;

typedef sf::Event event_t;
typedef std::shared_ptr<IWorldsObject> pWObject_t;
typedef std::vector<pWObject_t> wObjects_t;
typedef sf::RenderWindow window_t;

class IWorldsObject {
protected:
    struct Attributes : public BaseShape {
        bool solid;
        bool harmful;
        int groupID;

        Attributes(bool solid = true, int groupID = 0) : solid(solid), groupID(groupID) {}
        ~Attributes() {}
        bool isSolid();
        bool isHarmful();
        int getGroupID();
    };
    typedef  IWorldsObject::Attributes Collision;

    GameMap* map;
    wObjects_t* wObjects;
    window_t * window;
    Delegate destroyingSignal;

    typedef std::function<void()> Deferred;  
    std::function<void(Deferred)> pushDeferred;

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

    virtual Attributes& getAttr() = 0;
    virtual void setDeferredPusher(std::function<void(Deferred)>&&);

    
};





#endif /* end of include guard: _IWORLDSOBJECT_HPP_ */
