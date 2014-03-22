//#include "GameStates/GameIsOnState.hpp"
#include "GameStates/GameIsOnState.hpp"

GameIsOnState::GameIsOnState()
{
}

GameIsOnState::~GameIsOnState()
{
}

void GameIsOnState::update(event_t & event, float dt)
{
    stage->update(event, dt);
}

void GameIsOnState::draw()
{
    renderWindowPtr->clear();
    stage->draw();
}
    
void GameIsOnState::processState(event_t & event, float dt)
{
    std::cout << "GameIsOnState::processState   " << std::endl;
    update(event, dt);
    draw(); 
    display();
}
    
