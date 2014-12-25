#include "Game/CollisionManager.hpp"

CollisionManager::CollisionManager() :
wObjects(0)
{ 
} 

CollisionManager::~CollisionManager()
{
}

CollisionManager::iterator::iterator(WObjects* wObjects, IWObjectPtr exclude, WObjects::iterator it) :
wObjects(wObjects),
exclude(exclude),
it(it)
{
}

CollisionManager::iterator::iterator() :
wObjects(),
exclude(),
it()
{
}

CollisionManager::iterator::iterator(const iterator& second ) :
wObjects(),
exclude(),
it()
{
}

CollisionManager::iterator CollisionManager::begin()
{
    iterator temp = iterator(wObjects, owner, wObjects->begin());
    temp.findNext();
    return temp;
}

CollisionManager::iterator CollisionManager::end()
{
    return iterator(wObjects, owner, wObjects->end());
}

void CollisionManager::setWObjects(WObjects& wObjects)
{
    this->wObjects = & wObjects;
}

void CollisionManager::setTrackedObj(IWObjectPtr owner)
{
    this->owner = owner;
}