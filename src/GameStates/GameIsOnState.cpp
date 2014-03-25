//#include "GameStates/GameIsOnState.hpp"
#include "GameStates/GameIsOnState.hpp"

GameIsOnState::GameIsOnState()
{
}

GameIsOnState::~GameIsOnState()
{
}

void GameIsOnState::update(float dt)
{

    stage->update(dt);
}

void GameIsOnState::draw()
{
   
    pRenderWindow->clear(sf::Color::White);
    stage->draw();
}
    
void GameIsOnState::processState(float dt)
{
    //
    update(dt);
    draw(); 

    display();
}
    
