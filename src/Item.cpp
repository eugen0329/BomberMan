#include "Item.hpp"

Item::Item(GameMap& map_a, std::vector<WorldsObject*>& worldsObjectVector_a) : WorldsObject(map_a, worldsObjectVector_a)
{
}

Item::~Item()
{
}

void Item::changeState()
{
}
void Item::draw()
{
}

Vector2D<size_t> Item::getPos()
{
    return pos; 
}
