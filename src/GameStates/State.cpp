#include "State.hpp"

State::State(renderWindow_t * renderWindow) : renderWindowPtr(renderWindow)
{
}

State::State()
{
}

State::~State()
{
}

void State::display()
{
    renderWindowPtr->display();      
}

void State::setRenderWindow(renderWindow_t * renderWindowPtr)
{
    this->renderWindowPtr = renderWindowPtr;
}
