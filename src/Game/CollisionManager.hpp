#ifndef _COLLISIONMANAGER_HPP_
#define _COLLISIONMANAGER_HPP_

#include <iostream>
#include <vector>
#include <memory>

#include "Common/Algorithms.hpp"
#include "Common/BaseShape.hpp"

#include "Game/Attributes/IAttributes.hpp"
#include "Game/WObjects/IWorldsObject.hpp"

class CollisionManager {
private:
    typedef std::shared_ptr<IWorldsObject> pWObject_t;
    typedef std::vector<pWObject_t> wObjects_t;


    pWObject_t owner;

    wObjects_t* wObjects;
    wObjects_t::iterator it;
private:
    inline bool isSameObject(pWObject_t& verifiable) 
    {
        return verifiable == owner;
    }
    inline bool isCollided(pWObject_t& verifiable)
    {
        return alg::isCrossing(static_cast<BaseShape>(owner->getAttributes()), 
                               static_cast<BaseShape>(verifiable->getAttributes()) )  &&
               ! isSameObject(verifiable);
    } 
    inline pWObject_t findCollision()
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

    inline pWObject_t firstCollision()
    {
        this->it = wObjects->begin();
        return findCollision();
    }
    inline pWObject_t nextCollision()
    {
        it++;
        return findCollision();
    }

    void setWObjects(wObjects_t&);
    inline void setOwner(pWObject_t owner)
    {
        this->owner = owner;
    }
    //inline void setOwner(IWorldsObject *& owner)
    //{
    //    this->owner = std::make_shared<IWorldsObject>(owner);
    //}
};

#endif /* end of include guard: _COLLISIONMANAGER_HPP_ */
