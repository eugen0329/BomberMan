#include "GameMap.hpp"

GameMap::GameMap(size_t xSize, size_t ySize) : grid(xSize, ySize)
{
}

GameMap::GameMap() 
{
    size.x = 20;
    size.y = 15;
    grid.setSize(size.x, size.y);

    if(! rendTexture.create(size.x * 32, size.y * 32) ) {
        exit(1);
    }
    rendTexture.clear(sf::Color::Red);
    for(unsigned int i = 0; i < size.y; i++) {
        for(unsigned int j = 0; j < size.x; j++) {
            grid[i][j].sprite.setPosition(j*32, i*32);
            rendTexture.draw(grid[i][j].sprite);
        }
    }
    rendTexture.display();

    mapSprite.setPosition(0, 0);
    //mapSprite.setColor(sf::Color::Red);
    mapSprite.setTexture(rendTexture.getTexture());

}

GameMap::GameMap(const GameMap& second) : grid(second.grid)
{
}

GameMap::~GameMap()
{
}


//Matrix<cell_t> & GameMap::getGridRef()
//{
//    return grid;
//}

Matrix<cell_t> * GameMap::getGridPtr()
{
    return &grid;
}

void GameMap::setSize(size_t x, size_t y)
{
    grid.setSize(x, y);
}

void GameMap::setRenderWindow(renderWindow_t & renderWindow)
{
    pRenderWindow = &renderWindow;
}

void GameMap::draw()
{
    //std::cout << "GM draw, ";
    pRenderWindow->draw(mapSprite);
}

void GameMap::update(float dt)
{
}

