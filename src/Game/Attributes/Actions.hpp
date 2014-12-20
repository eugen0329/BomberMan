#ifndef _ACTIONS_HPP_
#define _ACTIONS_HPP_

#include <list>
#include <cmath>
#include <map>
#include <string>

#include "XMLParser/tinyxml.h"

#include "Common/Delegate.hpp"

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Bomb.hpp"

#include "Game/Attributes/PlayerAttributes.hpp"
#include "Rendering/AnimationManager.hpp"
#include "Common/Angle.hpp"
#include "Common/Algorithms.hpp"

//class Player;
class Actions;

typedef Actions actions_t;

class Actions {
private:
    PlayerAttributes * attrib;
    AnimationManager * anim;

    wObjects_t * wObjects;
    
    typedef std::list<Angle> directions_t;
    directions_t dir;

    Delegate createWObject;
    Delegate addCollisionExclude;
public:
    Actions(PlayerAttributes &, AnimationManager &);
    Actions();
    ~Actions();

    void calculateAngle();
    void move(float);
    void stop(float);
    void throwBomb(const std::string);

    void changeAnimation(const std::string&);
    
    inline float getVx()
    {
        return attrib->vMax * cos(attrib->angle.inRad());
    }
    inline float getVy()
    {
        return attrib->vMax * sin(attrib->angle.inRad());
    }
    inline void setNewGradAngle(float angle)
    {
        float newAngle = ( angle + attrib->angle.inGrad() ) / 2;
        attrib->angle.setGradAngle(newAngle);
    }
    
    void setPlayerAttr(PlayerAttributes &);
    void setWObjects(wObjects_t&);
    void setAnimationManager(AnimationManager &);
    void setSignal(Delegate*, std::string);
};



#endif /* end of include guard: _ACTIONS_HPP_ */
