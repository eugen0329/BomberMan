#include "Game/WObjects/IWorldsObject.hpp"

IWorldsObject::IWorldsObject(WObjects& wObjects, window_t& window) :
wObjects(&wObjects), 
window(&window)
{
}

IWorldsObject::IWorldsObject()
{
}

IWorldsObject::~IWorldsObject()
{
}

void IWorldsObject::setWorldObjects(WObjects& wObjects)
{
    this->wObjects = &wObjects;
}

void IWorldsObject::setWindow(window_t& window)
{
    this->window = &window; 
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

void IWorldsObject::setFnPushDeferred(pushDef_t&& pushDeferred)
{
   this->pushDeferred = pushDeferred;
}