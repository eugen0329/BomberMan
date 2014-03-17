#include "WorldsObjects/WorldsObject.hpp"

WorldsObject::~WorldsObject()
{
}

WorldsObject::WorldsObject(GameMap& map, std::vector<WorldsObject*>& worldsObjectVector) :
map(map), worldsObjectVector(worldsObjectVector)
{
}
