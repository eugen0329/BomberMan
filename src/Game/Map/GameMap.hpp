#ifndef _GAMEMAP_HPP_
#define _GAMEMAP_HPP_

#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Common/Matrix.hpp"
#include "Common/Vec2.hpp"
#include "Game/Map/Cell.hpp"
#include <exception>

typedef sf::RenderTexture renderableTexture_t;
typedef sf::Sprite sprite_t;
typedef sf::RenderWindow window_t;

class GameMap {
public:
    Matrix<cell_t> grid;
    Vec2<size_t> cellSize;
    Vec2<size_t> size;
private:
    window_t * window;
    renderableTexture_t rendTexture;
    sprite_t mapSprite;

    
    void loadGrid();
public:

    GameMap();
    GameMap(size_t xSize, size_t ySize);
    GameMap(const GameMap&);
    ~GameMap();


    void draw();
    void update(float dt);

    void setSize(size_t, size_t);
    void setWindow(window_t &);
    //Matrix<cell_t> & getGridRef();
    Matrix<cell_t> * getGridPtr();
};

#endif /* end of include guard: _GAMEMAP_HPP_ */
