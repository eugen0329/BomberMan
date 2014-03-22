#include "Person.hpp"

Person::Person(GameMap& map, std::vector<WorldsObject*>& wObjV, renderWindow_t& rendWindow) : 
WorldsObject(map, wObjV, rendWindow)
{
}

//Person::Person()
//{
//}

Person::~Person()
{
}

Vector2D<size_t> Person::getPos() 
{ 
    return pos; 
}
