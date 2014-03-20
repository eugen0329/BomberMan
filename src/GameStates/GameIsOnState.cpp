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
    stage->draw();
}

void GameIsOnState::update(float dt)
{
    stage->update(dt);
}
    
void GameIsOnState::processState()
{
    update(timer.getElapsedTime());
    draw(); 
    display();
}
    
