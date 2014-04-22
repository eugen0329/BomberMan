#include "Game/WObjects/IWorldsObject.hpp"

IWorldsObject::IWorldsObject(GameMap& map, wObjects_t& wObjV, window_t& window) :
map(&map), 
wObjects(&wObjV), 
window(&window)
{
    //solid = false;
}

IWorldsObject::IWorldsObject()
{
    //solid = false;
}

IWorldsObject::~IWorldsObject()
{
}

void IWorldsObject::setMap(GameMap& map)
{
    this->map = &map;
}

void IWorldsObject::setWorldsObjectsVector(wObjects_t& wObjects)
{
    this->wObjects = &wObjects;
}

void IWorldsObject::setRenderWindow(window_t& window)
{
    this->window = &window; 
}


//void IWorldsObject::setSignalsQueue(signals_t& signals)
//{
//    this->signals = &signals; 
//}
