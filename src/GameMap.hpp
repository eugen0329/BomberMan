#ifndef _GAMEMAP_HPP_
#define _GAMEMAP_HPP_

#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Matrix.hpp"
#include "Vector2D.hpp"
#include "Cell.hpp"
#include <exception>

typedef sf::RenderTexture renderableTexture_t;
typedef sf::Sprite sprite_t;
typedef sf::RenderWindow renderWindow_t;

class GameMap {
private:
    Matrix<cell_t> grid;
    renderWindow_t * pRenderWindow;
    renderableTexture_t rendTexture;
    sprite_t mapSprite;

    Vector2D<size_t> size;
    Vector2D<size_t> cellSize;
    
    void loadGrid();
public:
    GameMap();
    GameMap(size_t xSize, size_t ySize);
    GameMap(const GameMap&);
    ~GameMap();


    void draw();
    void update(float dt);

    void setSize(size_t, size_t);
    void setRenderWindow(renderWindow_t &);
    //Matrix<cell_t> & getGridRef();
    Matrix<cell_t> * getGridPtr();
};

#endif /* end of include guard: _GAMEMAP_HPP_ */
