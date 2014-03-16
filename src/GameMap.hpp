#ifndef _GAMEMAP_HPP_
#define _GAMEMAP_HPP_

#include "Matrix.hpp"

class GameMap {
private:
    Matrix<char> grid;
public:
    GameMap(size_t, size_t);
    GameMap(const GameMap&);
    ~GameMap();
    
    const Matrix<char>& getGridRef();
};

#endif /* end of include guard: _GAMEMAP_HPP_ */
