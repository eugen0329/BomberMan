#include "Person.hpp"

Person::Person(GameMap& map, std::vector<WorldsObject*>& worldsObjectVector) : WorldsObject(map, worldsObjectVector)
{
}

Person::~Person()
{
}

Vector2D<size_t> Person::getPos()
{
    return pos; 
}
