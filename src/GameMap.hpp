#ifndef _GAMEMAP_HPP_
#define _GAMEMAP_HPP_

#include "Matrix.hpp"

class GameMap {
private:
    Matrix<char> grid;
public:
    GameMap();
    GameMap(size_t xSize, size_t ySize);
    GameMap(const GameMap&);
    ~GameMap();

    void draw();
    void update();

    void setSize(size_t, size_t);
    const Matrix<char>& getGridRef();
};

#endif /* end of include guard: _GAMEMAP_HPP_ */
