#include "Game/CollisionManager.hpp"

CollisionManager::CollisionManager() :
wObjects(NULL)
{
}

CollisionManager::~CollisionManager()
{
}


void CollisionManager::setWObjects(wObjects_t& wObjects)
{
    this->wObjects = & wObjects;
}


