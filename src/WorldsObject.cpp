#include "WorldsObject.hpp"

WorldsObject::~WorldsObject()
{
}

WorldsObject::WorldsObject(GameMap& map_a, std::vector<WorldsObject*>& worldsObjectVector_a) :
map(map_a) , worldsObjectVector(worldsObjectVector_a)
{
}
