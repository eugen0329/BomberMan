#include "Game/LevelBackground.hpp"

LevelBackground::LevelBackground(size_t xSize, size_t ySize) : grid(xSize, ySize)
{
}

LevelBackground::LevelBackground() 
{
    loadGrid();

    if(! rendTexture.create(size.x * cellSize.x, size.y * cellSize.y) ) {
        exit(1);
    }

    rendTexture.clear(sf::Color::Blue);
    for(unsigned int i = 0; i < size.y; i++) {
        for(unsigned int j = 0; j < size.x; j++) {
            grid[i][j].sprite.setPosition(j * cellSize.x, i * cellSize.y);
            rendTexture.draw(grid[i][j].sprite);
        }
    }
    rendTexture.display();

    mapSprite.setPosition(0, 0);
    mapSprite.setTexture(rendTexture.getTexture());

}

void LevelBackground::loadGrid()
{
    
    size.x = 20;
    size.y = 15;
    grid.setSize(size.x, size.y);

    cellSize.x = 32;
    cellSize.y = 32;

    std::ifstream fMapGrid;

    fMapGrid.open(conf::backgroundGrid.c_str());
    if(! fMapGrid.is_open()) throw std::ios_base::failure("ERROR while opening file");

    std::string buffer;
    for(unsigned int i = 0; i < size.y; i++) {
        std::getline(fMapGrid, buffer);
        for(unsigned int j = 0; j < size.x; j++) {
            grid[i][j].cellID = buffer[j];
            if( grid[i][j].cellID == 'w') {
                grid[i][j].setTile("res/Tiles/wall.jpg");
            } else if (grid[i][j].cellID == 'f') {
                grid[i][j].setTile("res/Tiles/floor.gif");
            }
        }
    }

    fMapGrid.close();

}

LevelBackground::LevelBackground(const LevelBackground& second) : grid(second.grid)
{
}

LevelBackground::~LevelBackground()
{
} 

void LevelBackground::setSize(size_t x, size_t y)
{
    grid.setSize(x, y);
}

void LevelBackground::setWindow(window_t & window)
{
    this->window = &window;
}

void LevelBackground::draw()
{
    window->draw(mapSprite);
}

void LevelBackground::update(float dt)
{
}

void LevelBackground::Cell::setTile(std::string textureName)
{
    if(! texture.loadFromFile(textureName.c_str()) ) throw std::ios_base::failure("ERROR while loading file " + textureName);
    sprite.setTexture(texture);
}
