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
}

void GameIsOnState::update()
{
}

    
void GameIsOnState::processState()
{
    while(renderWindowPtr->isOpen()) {
        update();
        draw(); 
        
    }
}
    
