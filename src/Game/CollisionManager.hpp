#ifndef _COLLISIONMANAGER_HPP_
#define _COLLISIONMANAGER_HPP_

#include <iostream>
#include <vector>

#include "Common/Algorithms.hpp"
#include "Common/BaseShape.hpp"

#include "Game/Attributes/IAttributes.hpp"
#include "Game/WObjects/IWorldsObject.hpp"

class CollisionManager {
private:
    typedef std::vector<IWorldsObject*> wObjects_t;

    IWorldsObject* owner;

    wObjects_t* wObjects;
    wObjects_t::iterator it;
private:
    inline bool isSameObject(IWorldsObject *& verifiable) 
    {
        return verifiable == owner;
    }
    inline bool isCollided(IWorldsObject *& verifiable)
    {
        return alg::isCrossing(static_cast<BaseShape>(owner->getAttributes()), 
                               static_cast<BaseShape>(verifiable->getAttributes()) )  &&
               ! isSameObject(verifiable);
    } 
    inline IWorldsObject* findCollision()
    {
        wObjects_t::iterator last = wObjects->end();
        while(it != last) {
            if (isCollided(*it) && ! isSameObject(*it)) {
                return *it;
            }
            it++;
        }
        
        return 0;
    }
public:
    CollisionManager();
    ~CollisionManager();

    inline IWorldsObject* firstCollision()
    {
        this->it = wObjects->begin();
        return findCollision();
    }
    inline IWorldsObject* nextCollision()
    {
        it++;
        return findCollision();
    }

    void setWObjects(wObjects_t&);
    inline void setOwner(IWorldsObject& owner)
    {
        this->owner = & owner;
    }
};

#endif /* end of include guard: _COLLISIONMANAGER_HPP_ */
