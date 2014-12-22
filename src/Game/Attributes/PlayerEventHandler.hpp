#ifndef _PlayerEventHandler_HPP_
#define _PlayerEventHandler_HPP_

#include <list>
#include <cmath>
#include <map>
#include <string>

#include "TinyXML/tinyxml.h"

#include "Common/Delegate.hpp"

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Bomb.hpp"
#include "Game/Keyset.hpp"

#include "Game/Attributes/PlayerAttributes.hpp"
#include "Rendering/AnimationManager.hpp"
#include "Common/Angle.hpp"
#include "Common/Algorithms.hpp"


class Player;

class PlayerEventHandler {
    friend class Player;
private:
    PlayerAttributes * attr;
    AnimationManager * anim;
    wObjects_t * wObjects;

    Keyset * keys;
    
    typedef std::list<Angle> directions_t;
    directions_t dir;

    std::function<void(pWObject_t)> addCollisionExclude;

    Delegate createWObject;
    
public:
    PlayerEventHandler(PlayerAttributes &, AnimationManager &);
    PlayerEventHandler();
    ~PlayerEventHandler();

    void calcAngle();

    std::function<void(float)> move;
    std::function<void(const std::string&&)> throwBomb;
    std::function<void(float)> stop;

    virtual void handleEvents(const event_t&);
    void handleKeyPressedEvents(const event_t&);
    void handleKeyReleasedEvents(const event_t&);

    void changeAnimation(const std::string&);
    
    inline float getVx()
    {
        return attr->vMax * cos(attr->angle.inRad());
    }
    inline float getVy()
    {
        return attr->vMax * sin(attr->angle.inRad());
    }
    inline void setNewGradAngle(float angle)
    {
        float newAngle = ( angle + attr->angle.inGrad() ) / 2;
        attr->angle.setGradAngle(newAngle);
    }
    
    void setPlayerAttr(PlayerAttributes &);
    void setWObjects(wObjects_t&);
    void setAnimationManager(AnimationManager &);
    void setSignal(Delegate*, std::string);
    void setKeyset(Keyset * keyset);

    void setAction(Delegate* delegate, std::string signalName);


    void load(PlayerAttributes & attr, AnimationManager& anim);
};



#endif /* end of include guard: _PlayerEventHandler_HPP_ */
