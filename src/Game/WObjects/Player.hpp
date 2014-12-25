#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_


#include <vector>

#include <list>
#include <cmath>
#include <memory>
#include <stack>
#include <cstdint> /* int8_t */

#include "SFML/Graphics.hpp"

#include "Rendering/AnimationManager.hpp"
#include "Common/Algorithms.hpp"

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Actor.hpp"
#include "Game/CollisionManager.hpp"
#include "Game/Keyset.hpp"
#include "Game/WObjects/Bomb.hpp"
#include "Game/DrawableScene.hpp"

class Player : public Actor {
protected:
    struct Attributes : public Actor::Attributes {
        Keyset * keys;
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

    void throwBomb();
    void move(float vx, float vy);

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


#endif /* end of include guard: _PLAYER_HPP_ */
