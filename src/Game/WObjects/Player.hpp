#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include <memory>

#include <stack>
#include <cstdint> /* int8_t */


#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Actor.hpp"

#include "Common/Interfaces/IInitializer.hpp"

#include "Common/Algorithms.hpp"
#include "Game/CollisionManager.hpp"


#include "Game/Attributes/IAttributes.hpp"
#include "Game/Attributes/PlayerAttributes.hpp"
#include "Game/Keyset.hpp"
#include "Game/WObjects/Bomb.hpp"

#include "Rendering/AnimationManager.hpp"

#include "SFML/Graphics.hpp"

class Player : public Actor {
private:
    typedef TiXmlElement xmlElem_t;
    typedef std::shared_ptr<IWorldsObject> pWObject_t;
    typedef std::list<pWObject_t> collisionExcludes_t;
    class Initializer;

    AnimationManager anim;
    PlayerAttributes attr;
    CollisionManager* collisions;
    collisionExcludes_t collisionExcludes;

    std::function<void(float, float)> move;
    std::function<void()> throwBomb;
    //std::function<void(float)> stop;
    Delegate createWObject;

    Delegate* createSignal;

    enum class ACTIONS : std::int8_t {
        MOVE_UP, 
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT,
        THROW_BOMB,
        COUNT
    };
    typedef std::function<void(const float&)> action_t;
    
    Keyset * keys;
    std::map<ACTIONS,action_t> actBinds;        // action bindings
    std::map<sf::Keyboard::Key, ACTIONS> keyBinds;
    std::stack<action_t> actions;
    std::string lastDirection;


public:
    Player();
    Player(xmlElem_t&);
    virtual ~Player();
    virtual void addCollision(Collision) {};

    void handleEvents(const event_t&);
    void handleRealtimeEvents();
    void update(const float&);
    void draw();

    void updateCoordinates(const float&);
    
    bool hasSolidCollisions();
    bool isExclude(pWObject_t);


    void handleCollisions();
    void updateCollisionExcludes();
    
    void changeAnimation();

    IAttributes& getAttr() 
    {
        return attr;
    }
    virtual void setWorldObjects(wObjects_t&);
    void setSignal(Delegate*, std::string);
    void load(xmlElem_t&);
};



#endif /* end of include guard: _PLAYER_HPP_ */
