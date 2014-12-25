#include "Game/CollisionManager.hpp"

CollisionManager::CollisionManager() :
wObjects(0)
{ 
} 

CollisionManager::~CollisionManager()
{
}

CollisionManager::iterator::iterator(wObjects_t* wObjects, pWObject_t exclude, wObjects_t::iterator it) :
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

void CollisionManager::setWObjects(wObjects_t& wObjects)
{
    this->wObjects = & wObjects;
}

void CollisionManager::setTrackedObj(pWObject_t owner)
{
    this->owner = owner;
}