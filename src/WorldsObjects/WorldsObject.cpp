#include "WorldsObjects/WorldsObject.hpp"

WorldsObject::~WorldsObject()
{
}

WorldsObject::WorldsObject(GameMap& map, std::vector<WorldsObject*>& wObjV, renderWindow_t& rendWindow) :
map(map), worldsObjectVector(wObjV), renderWindow(rendWindow)
{
}
