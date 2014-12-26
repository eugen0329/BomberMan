#ifndef _CELL_HPP_
#define _CELL_HPP_

#include <exception>
#include <SFML/Graphics.hpp>
#include "Common/BasicTypes.hpp"

class Cell;
typedef Cell cell_t;
typedef char cellID_t;

class Cell {
private:
    cellID_t cellID;
    texture_t texture;
    sprite_t sprite;
public:
    friend class GameMap;
    Cell(cellID_t cellID);
    Cell();
    ~Cell();
    inline cellID_t getID()
    {
        return this->cellID;
    }

    void setTile(std::string);
    void setID(cellID_t);
    
};

#endif /* end of include guard: _CELL_HPP_ */
