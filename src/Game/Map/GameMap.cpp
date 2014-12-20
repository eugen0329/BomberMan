#include "GameMap.hpp"

GameMap::GameMap(size_t xSize, size_t ySize) : grid(xSize, ySize)
{
}

GameMap::GameMap() 
{
    loadGrid();

    if(! rendTexture.create(size.x * cellSize.x, size.y * cellSize.y) ) {
        exit(1);
    }

    rendTexture.clear(sf::Color::Blue);
    for(unsigned int i = 0; i < size.y; i++) {
        for(unsigned int j = 0; j < size.x; j++) {
            //grid[i][j].setTile("res/Tiles/stone.gif");
            grid[i][j].sprite.setPosition(j * cellSize.x, i * cellSize.y);
            rendTexture.draw(grid[i][j].sprite);
        }
    }
    rendTexture.display();

    mapSprite.setPosition(0, 0);
    //mapSprite.setColor(sf::Color::Red);
    mapSprite.setTexture(rendTexture.getTexture());

}

void GameMap::loadGrid()
{
    
    size.x = 20;
    size.y = 15;
    grid.setSize(size.x, size.y);

    cellSize.x = 32;
    cellSize.y = 32;

    std::ifstream fMapGrid;
    fMapGrid.open("res/mapGrid");
    //fMapGrid.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    if(! fMapGrid.is_open() ) {
        throw std::ios_base::failure("ERROR while opening file");
    }
    std::string buffer;
    
    for(unsigned int i = 0; i < size.y; i++) {
        std::getline(fMapGrid, buffer);
        for(unsigned int j = 0; j < size.x; j++) {
            grid[i][j].setID(buffer[j]);
            if( grid[i][j].getID() == 'w') {
                grid[i][j].setTile("res/Tiles/wall.jpg");
                //grid[i][j].setSolid(true);
            } else if (grid[i][j].getID() == 'f') {
                grid[i][j].setTile("res/Tiles/floor.gif");
                //grid[i][j].setSolid(false);
            }
        }
    }

    fMapGrid.close();

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

void GameMap::setRenderWindow(window_t & window)
{
    this->window = &window;
}

void GameMap::draw()
{
    window->draw(mapSprite);
}

void GameMap::update(float dt)
{
}

