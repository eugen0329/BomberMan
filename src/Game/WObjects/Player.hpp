#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include <memory>

#include "Game/Attributes/Actions.hpp"

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Actor.hpp"

#include "Common/Interfaces/IInitializer.hpp"

#include "Common/Algorithms.hpp"

#include "Game/CollisionManager.hpp"

#include "Game/Attributes/PlayerEventManager.hpp"
#include "Game/Attributes/IAttributes.hpp"
#include "Game/Attributes/PlayerAttributes.hpp"

#include "Rendering/AnimationManager.hpp"

#include "SFML/Graphics.hpp"

class Player : public Actor {
private:
    typedef TiXmlElement xmlElement_t;
    typedef std::list<IWorldsObject*> collisionExcludes_t;
    class Initializer;

    PlayerAttributes attrib;
    AnimationManager animationManager;
    Actions act;
    PlayerEventManager eventManager;

    CollisionManager* collisions;
    collisionExcludes_t collisionExcludes;

    Delegate* createSignal;
private:
    void initializeComponents(xmlElement_t&);

    void cancelHorizontalOffsetIfNeed(wObjects_t::iterator&, const float&);
    void cancelVerticalOffsetIfNeed(wObjects_t::iterator&, const float&);
public:
    Player();
    Player(xmlElement_t&);
    virtual ~Player();

    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();

    void updateCoordinates(const float&);
    
    bool checkCollisions();
    bool isExclude(IWorldsObject*);

    virtual void addCollision(Collision) {}
    void handleCollisions();
    void updateCollisionExcludes();
    void addCollisionExclude(IWorldsObject*) ;
    
    IAttributes& getAttributes() 
    {
        return attrib;
    }
    virtual void setWorldsObjectsVector(wObjects_t&);
    void setSignal(Delegate*, std::string);
};

class Player::Initializer : public IInitializer {
private:
    mutable PlayerAttributes* attrib; 
public:
    Initializer();
    Initializer(xmlElement_t&, PlayerAttributes&);
    virtual ~Initializer();
    
    int load() const;
    
};

#endif /* end of include guard: _PLAYER_HPP_ */
