#include "Cell.hpp"

//Cell::Cell(cellID_t cellID, bool solid) : cellID(cellID), solid(solid)
Cell::Cell(cellID_t cellID) : cellID(cellID)
{ 
}

Cell::Cell() 
{
    //this->cellID = ' ';
    //this->solid = false;
    //if(! texture.loadFromFile("res/Tiles/stone.gif")) {
    //    exit(1);
    //}
    //sprite.setTexture(texture);
}

Cell::~Cell()
{
}

void Cell::setTile(std::string textureName)
{
    if(! texture.loadFromFile(textureName.c_str())) {
        exit(1);
    }
    sprite.setTexture(texture);
}

void Cell::setID(cellID_t cellID)
{
    this->cellID = cellID;
}

//void Cell::setSolid(bool solid)
//{
//    this->solid = solid;
//}
