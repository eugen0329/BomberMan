//#include "GameStates/GameState.hpp"
#include "Game/GameState.hpp"

GameState::GameState()
{
}

GameState::~GameState()
{
    delete level;
}

void GameState::handleEvents(const event_t& event)
{
    level->handleEvents(event);
}

void GameState::update(const float& dt)
{

    level->update(dt);
}

void GameState::draw()
{
   
    window->clear(sf::Color::White);
    level->draw();
}
