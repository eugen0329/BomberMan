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
    struct DamageImmunity {
        float timer;
        float maxTime;
        bool isActive;

        operator bool() {
            return isActive;
        }
    };
    
    struct Attributes : public Actor::Attributes {
        Keyset * keys;
        float damageImunityTime;
        float maxInvulnerablityTime;
        DamageImmunity immunity;
        sf::Color oldColor;
        
        sf::Text healthIndicator;
        sf::Font indicatorFont;
        ~Attributes();
    };

    typedef TiXmlElement xmlElem_t;
    typedef std::shared_ptr<IWorldsObject> IWObjectPtr;
    typedef std::list<IWObjectPtr> collisionExcludes_t;

    enum class ACTIONS : std::int8_t {
        MOVE_UP, 
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT,
        THROW_BOMB,
        COUNT
    };
    typedef std::function<void(const float&)> action_t;

    AnimationManager anim;
    Attributes attr;
    CollisionManager* collisManager;
    collisionExcludes_t collisionExcludes;

    std::stack<Collision> foreignCollisions;
    std::map<ACTIONS,action_t> actBinds;        // action bindings
    std::map<sf::Keyboard::Key, ACTIONS> keyBinds;
    std::stack<action_t> actions;
    std::string lastDirection;


    void updateImmunityState(const float&);
    void throwBomb();
    void move(float vx, float vy);
public:
    Player();
    Player(xmlElem_t&);
    virtual ~Player();
    virtual void addCollision(Collision);

    void handleEvents(const event_t&);
    void handleRealtimeEvents();
    void update(const float&);
    void draw();

    void updateCoordinates(const float&);
    void updateAnimation(const float& dt);

    void updateCollisions();
    void handleCollision(Collision & collision);

    void updateCollisionExcludes();
    
    virtual IWorldsObject::Attributes& getAttr();

    virtual void setWorldObjects(WObjects&);
    void load(xmlElem_t&);

    bool hasSolidCollisions();
    bool isNoLongerExisted(const collisionExcludes_t::iterator&);
    bool isExclude(IWObjectPtr);


};


#endif /* end of include guard: _PLAYER_HPP_ */
