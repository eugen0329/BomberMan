#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <vector>
#include <queue>
#include <cmath>
#include <memory>

#include "Game/Attributes/Actions.hpp"

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Actor.hpp"

#include "Common/Interfaces/IInitializer.hpp"

#include "Common/Algorithms.hpp"


#include "Game/Attributes/PlayerEventManager.hpp"
#include "Game/Attributes/IAttributes.hpp"
#include "Game/Attributes/PlayerAttributes.hpp"

#include "Rendering/AnimationManager.hpp"

#include "SFML/Graphics.hpp"

class Player : public Actor {
private:
    typedef TiXmlElement xmlElement_t;
    class Initializer;

    PlayerAttributes attrib;
    AnimationManager animationManager;
    Actions act;
    PlayerEventManager eventManager;

    Delegate* createSignal;
private:
    void initializeAggregates(xmlElement_t&);

    void checkVerticalCollisions(const float& dt);  
    void checkHorizontalCollisions(const float& dt);      
    void cancelHorizontalOffsetIfNeed(wObjects_t::iterator&, const float&);
    void cancelVerticalOffsetIfNeed(wObjects_t::iterator&, const float&);
public:
    Player();
    Player(xmlElement_t&);
    virtual ~Player();

    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();

    bool isCrossing(IWorldsObject&);
    void updateCoordinates(const float&);

    
    void setSignal(Delegate*, std::string);

    IAttributes getAttributes() 
    {
        return attrib;
    }
    inline bool isSameObject(const wObjects_t::iterator& it) 
    {
        return (*it) == dynamic_cast<IWorldsObject*>(this);
    }
    inline bool isCollided(const wObjects_t::iterator& it)
    {
        return alg::isCrossing(this->attrib, (*it)->getAttributes())  &&
               (*it)->getAttributes().isSolid();
    } 
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
