#include "Cell.hpp"

Cell::Cell(cellID_t cellID, bool solid) : cellID(cellID), solid(solid)
{ 
}

Cell::Cell() 
{
    this->cellID = ' ';
    this->solid = false;
    if(! texture.loadFromFile("res/Tiles/stone.gif")) {
        exit(1);
    }
    sprite.setTexture(texture);
}

Cell::~Cell()
{
}
