#include "WorldsObjects/Actor.hpp"

Actor::Actor(GameMap& map, std::vector<WorldsObject*>& wObjV, renderWindow_t& rendWindow) : 
WorldsObject(map, wObjV, rendWindow)
{
}

//Actor::Actor()
//{
//}

Actor::~Actor()
{
}

Vector2D<size_t> Actor::getPos() 
{ 
    return pos; 
}
