#ifndef _COLLISIONMANAGER_HPP_
#define _COLLISIONMANAGER_HPP_

#include <iostream>
#include <vector>
#include <memory>

#include "Common/Algorithms.hpp"
#include "Common/BaseShape.hpp"


#include "Game/WObjects/IWorldsObject.hpp"

typedef std::vector<IWObjectPtr> WObjects;
typedef std::shared_ptr<IWorldsObject> IWObjectPtr;

class CollisionManager {
public:
    class iterator;
private:
    IWObjectPtr owner;

    WObjects* wObjects;
    WObjects::iterator it;
public:
    CollisionManager();
    ~CollisionManager();

    iterator begin();
    iterator end();


    void setWObjects(WObjects& wObjects);

    void setTrackedObj(IWObjectPtr owner);

};


class CollisionManager::iterator {
private:
    friend class CollisionManager;

    WObjects* wObjects;
    IWObjectPtr exclude;
    WObjects::iterator it;

    inline bool isSameObject(IWObjectPtr& verifiable) 
    {
        return verifiable == exclude;
    }
    inline bool isCollided(IWObjectPtr& verifiable)
    {
        return alg::isCrossing(static_cast<BaseShape>(exclude->getAttr()), 
                               static_cast<BaseShape>(verifiable->getAttr()) )  &&
               ! isSameObject(verifiable);
    } 
    inline void findNext() 
    {
        WObjects::iterator last = wObjects->end();
        while(it != last) {
            if (isCollided(*it) && ! isSameObject(*it) ) {
                break;
            }
            it++;
        }
    }
public:
    iterator(WObjects* wObjects, IWObjectPtr exclude, WObjects::iterator it);
    iterator();

    iterator(const iterator& second );

    inline iterator& operator ++ () 
    {
        it++;
        findNext();
        return *this;
    }
    inline IWObjectPtr& operator * () 
    {
        return *it;
    }
    inline IWObjectPtr& operator -> () 
    {
        return *it;
    }
    inline bool operator != (const iterator& second) 
    {
        return it != second.it;
    }
};


#endif /* end of include guard: _COLLISIONMANAGER_HPP_ */
