#include "Person.hpp"

Person::Person(GameMap& map_a, std::vector<WorldsObject*>& worldsObjectVector_a) : WorldsObject(map_a, worldsObjectVector_a)
{
}

Person::~Person()
{
}

void Person::changeState()
{
}
void Person::draw()
{
}

Vector2D<size_t> Person::getPos()
{
    return pos; 
}
