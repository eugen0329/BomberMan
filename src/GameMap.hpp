#ifndef _GAMEMAP_HPP_
#define _GAMEMAP_HPP_

#include "Matrix.hpp"
#include "Cell.hpp"

class GameMap {
private:
    Matrix<cell_t> grid;
public:
    GameMap();
    GameMap(size_t xSize, size_t ySize);
    GameMap(const GameMap&);
    ~GameMap();

    void draw();
    void update(float dt);

    void setSize(size_t, size_t);
    Matrix<cell_t> & getGridRef();
    Matrix<cell_t> * getGridPtr();
};

#endif /* end of include guard: _GAMEMAP_HPP_ */
