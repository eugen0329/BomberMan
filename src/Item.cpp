#include "Item.hpp"

Item::Item(GameMap& map, std::vector<WorldsObject*>& worldsObjectVector) : WorldsObject(map, worldsObjectVector)
{
}

Item::~Item()
{
}

Vector2D<size_t> Item::getPos()
{
    return pos; 
}
