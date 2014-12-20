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
#include "Game/Keyset.hpp"

#include "Rendering/AnimationManager.hpp"

#include "SFML/Graphics.hpp"

class Player : public Actor {
private:
    typedef TiXmlElement xmlElem_t;
    typedef std::shared_ptr<IWorldsObject> pWObject_t;
    typedef std::list<pWObject_t> collisionExcludes_t;
    class Initializer;


    PlayerEventManager * eventManager;
    AnimationManager animationManager;
    
    Actions act;
    PlayerAttributes attr;

    CollisionManager* collisions;
    collisionExcludes_t collisionExcludes;

    Delegate* createSignal;
public:
    Player();
    Player(xmlElem_t&);
    virtual ~Player();

    void handleEvents(const event_t&);
    void update(const float&);
    void draw();

    void updateCoordinates(const float&);
    
    bool hasSolidCollisions();
    bool isExclude(pWObject_t);

    void addCollision(Collision);
    void handleCollisions();
    void updateCollisionExcludes();
    void addCollisionExclude(pWObject_t) ;
    


    IAttributes& getAttr() 
    {
        return attr;
    }
    virtual void setWorldObjects(wObjects_t&);
    void setSignal(Delegate*, std::string);
};

class Player::Initializer : public IInitializer {
private:
    mutable PlayerAttributes* attr; 
public:
    Initializer();
    Initializer(xmlElem_t&, PlayerAttributes&);
    virtual ~Initializer();
    
    int load() const;
    
};

#endif /* end of include guard: _PLAYER_HPP_ */
