#include "WorldsObjects/WorldsObject.hpp"

WorldsObject::~WorldsObject()
{
}

WorldsObject::WorldsObject(GameMap& map, std::vector<WorldsObject*>& wObjV, renderWindow_t & renderWindow) :
map(map), worldsObjectVector(wObjV), pRenderWindow(&renderWindow)
{
}
