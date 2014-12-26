#ifndef _SLUG_HPP_
#define _SLUG_HPP_


#include <vector>

#include <list>
#include <cmath>
#include <memory>
#include <stack>
#include <cstdint> /* int8_t */

#include "SFML/Graphics.hpp"

#include "Rendering/AnimationManager.hpp"
#include "Common/Algorithms.hpp"


#include "Game/WObjects/Blow.hpp"
#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Actor.hpp"
#include "Game/CollisionManager.hpp"
#include "Game/DrawableScene.hpp"

class Slug : public Actor {
protected:
    struct Attributes : public Actor::Attributes {
        IWObjectPtr target;
        ~Attributes();
    };

    typedef TiXmlElement xmlElem_t;
    typedef std::shared_ptr<IWorldsObject> IWObjectPtr;
    typedef std::list<IWObjectPtr> collisionExcludes_t;
    class Initializer;

    AnimationManager anim;
    Attributes attr;
    CollisionManager* collisions;
    collisionExcludes_t collisionExcludes;

    void move();
    void chooseTarget();

    typedef std::function<void(const float&)> action_t;
    

public:
    Slug();
    Slug(xmlElem_t&, Vec2<float>);
    virtual ~Slug();
    virtual void addCollision(Collision) {};

    void handleEvents(const event_t&);
    void handleRealtimeEvents();
    void update(const float&);
    void draw();

    void updateCoordinates(const float&);
    void updateAnimation(const float& dt);

    void handleCollisions();
    void updateCollisionExcludes();
    
    virtual IWorldsObject::Attributes& getAttr();

    virtual void setWorldObjects(WObjects&);
    void setSignal(Delegate*, std::string);
    void load(xmlElem_t&);

    bool hasSolidCollisions();
    bool isNoLongerExisted(const collisionExcludes_t::iterator&);
    bool isExclude(IWObjectPtr);
};


#endif /* end of include guard: _SLUG_HPP_ */
