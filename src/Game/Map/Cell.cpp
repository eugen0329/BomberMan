#include "Cell.hpp"

Cell::Cell(cellID_t cellID) : cellID(cellID)
{ 
}

Cell::Cell() 
{
}

Cell::~Cell()
{
}

void Cell::setTile(std::string textureName)
{
    if(! texture.loadFromFile(textureName.c_str()) ) throw std::ios_base::failure("ERROR while loading file " + textureName);
    sprite.setTexture(texture);
}

void Cell::setID(cellID_t cellID)
{
    this->cellID = cellID;
}
