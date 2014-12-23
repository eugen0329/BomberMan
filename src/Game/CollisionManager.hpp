#ifndef _COLLISIONMANAGER_HPP_
#define _COLLISIONMANAGER_HPP_

#include <iostream>
#include <vector>
#include <memory>

#include "Common/Algorithms.hpp"
#include "Common/BaseShape.hpp"

#include "Game/Attributes/IAttributes.hpp"
#include "Game/WObjects/IWorldsObject.hpp"

typedef std::vector<pWObject_t> wObjects_t;
typedef std::shared_ptr<IWorldsObject> pWObject_t;

class CollisionManager {
public:
    class iterator;
private:
    pWObject_t owner;

    wObjects_t* wObjects;
    wObjects_t::iterator it;
public:
    CollisionManager();
    ~CollisionManager();

    iterator begin();
    iterator end();


    void setWObjects(wObjects_t& wObjects);

    void setOwner(pWObject_t owner);

};


class CollisionManager::iterator {
private:
    friend class CollisionManager;

    wObjects_t* wObjects;
    pWObject_t exclude;
    wObjects_t::iterator it;

    inline bool isSameObject(pWObject_t& verifiable) 
    {
        return verifiable == exclude;
    }
    inline bool isCollided(pWObject_t& verifiable)
    {
        return alg::isCrossing(static_cast<BaseShape>(exclude->getAttr()), 
                               static_cast<BaseShape>(verifiable->getAttr()) )  &&
               ! isSameObject(verifiable);
    } 
    inline void findNext() 
    {
        wObjects_t::iterator last = wObjects->end();
        while(it != last) {
            if (isCollided(*it) && ! isSameObject(*it) ) {
                break;
            }
            it++;
        }
    }
public:
    iterator(wObjects_t* wObjects, pWObject_t exclude, wObjects_t::iterator it);
    iterator();

    iterator(const iterator& second );

    inline iterator& operator ++ () 
    {
        it++;
        findNext();
        return *this;
    }
    inline pWObject_t& operator * () 
    {
        return *it;
    }
    inline pWObject_t& operator -> () 
    {
        return *it;
    }
    inline bool operator != (const iterator& second) 
    {
        return it != second.it;
    }
};


#endif /* end of include guard: _COLLISIONMANAGER_HPP_ */
