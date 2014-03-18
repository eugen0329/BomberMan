#include "GameIsOnState.hpp"

GameIsOnState::GameIsOnState()
{
}

GameIsOnState::~GameIsOnState()
{
}

void GameIsOnState::draw()
{
    renderWindowPtr->clear();
    stage.draw();
}

void GameIsOnState::update()
{
    stage.update();
}

    
void GameIsOnState::processState()
{
    while(renderWindowPtr->isOpen()) {
        update();
        draw(); 
        display();
    }
}
    
