#include "GameMap.hpp"

GameMap::GameMap(size_t xSize, size_t ySize) : grid(xSize, ySize)
{
}

GameMap::GameMap() 
{
}

GameMap::GameMap(const GameMap& second) : grid(second.grid)
{
}

GameMap::~GameMap()
{
}


Matrix<cell_t> & GameMap::getGridRef()
{
    return grid;
}

Matrix<cell_t> * GameMap::getGridPtr()
{
    return &grid;
}

void GameMap::setSize(size_t x, size_t y)
{
    grid.setSize(x, y);
}

void GameMap::draw()
{
}

void GameMap::update(float dt)
{
}

