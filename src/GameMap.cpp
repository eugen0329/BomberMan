#include "GameMap.hpp"

GameMap::GameMap(size_t xSize, size_t ySize) : grid(xSize, ySize)
{
}

GameMap::GameMap(const GameMap& second) : grid(second.grid)
{
    //this->grid = second.grid;
}

GameMap::~GameMap()
{
}


const Matrix<char>& GameMap::getGridRef()
{
    return grid;
}
