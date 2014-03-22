#include "GameStates/IState.hpp"

IState::IState(renderWindow_t * renderWindow) : renderWindowPtr(renderWindow)
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
    renderWindowPtr->display();      
}

void IState::setRenderWindow(renderWindow_t * renderWindowPtr)
{
    this->renderWindowPtr = renderWindowPtr;
}
