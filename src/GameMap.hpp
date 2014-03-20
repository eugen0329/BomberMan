#ifndef _GAMEMAP_HPP_
#define _GAMEMAP_HPP_

#include "Matrix.hpp"

typedef char cellID_t;
class GameMap;

class Cell {
private:
    bool solid;
    cellID_t cellID;
public:
    friend class GameMap;
    Cell(cellID_t cellID, bool solid = false);
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

class GameMap {
private:
    Matrix<char> grid;
public:
    GameMap();
    GameMap(size_t xSize, size_t ySize);
    GameMap(const GameMap&);
    ~GameMap();

    void draw();
    void update(float dt);

    void setSize(size_t, size_t);
    const Matrix<char>& getGridRef();
};

#endif /* end of include guard: _GAMEMAP_HPP_ */
