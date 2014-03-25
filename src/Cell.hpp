#ifndef _CELL_HPP_
#define _CELL_HPP_

#include <iostream>

#include <SFML/Graphics.hpp>

class Cell;
typedef Cell cell_t;
typedef char cellID_t;

typedef sf::Texture texture_t;
typedef sf::Sprite sprite_t;

class Cell {
private:
    cellID_t cellID;
    bool solid;
    
    texture_t texture;
    sprite_t sprite;

public:
    friend class GameMap;
    Cell(cellID_t cellID, bool solid = false);
    Cell();
    ~Cell();
    inline cellID_t getCellID()
    {
        return this->cellID;
    }
    inline bool isSolid()
    {
        return solid;
    }
    
};

#endif /* end of include guard: _CELL_HPP_ */
