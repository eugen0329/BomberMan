#include "Game/WObjects/IWorldsObject.hpp"

IWorldsObject::IWorldsObject(GameMap& map, wObjects_t& wObjV, window_t& window) :
map(&map), 
wObjects(&wObjV), 
window(&window)
{
}

IWorldsObject::IWorldsObject()
{
}

IWorldsObject::~IWorldsObject()
{
}

void IWorldsObject::setMap(GameMap& map)
{
    this->map = &map;
}

void IWorldsObject::setWorldObjects(wObjects_t& wObjects)
{
    this->wObjects = &wObjects;
}

void IWorldsObject::setRenderWindow(window_t& window)
{
    this->window = &window; 
}

void IWorldsObject::setDeferredPusher(std::function<void(Deferred)>&& deferred)
{
    this->pushDeferred = pushDeferred; 
}

bool IWorldsObject::Attributes::isSolid()
{
    return solid;
}
bool IWorldsObject::Attributes::isHarmful()
{
    return harmful;
}
int IWorldsObject::Attributes::getGroupID()
{
    return groupID;
}
