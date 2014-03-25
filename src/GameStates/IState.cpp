#include "GameStates/IState.hpp"

IState::IState(renderWindow_t * pRenderWindow) : pRenderWindow(pRenderWindow)
{
}

IState::IState()
{
}

IState::~IState()
{
}

void IState::display()
{
    pRenderWindow->display();      
}

void IState::setRenderWindow(renderWindow_t * pRenderWindow)
{
    this->pRenderWindow = pRenderWindow;
}
