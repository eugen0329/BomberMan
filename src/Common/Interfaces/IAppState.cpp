#include "Common/Interfaces/IAppState.hpp"

IAppState::IAppState(window_t& window) : window(&window)
{
}

IAppState::IAppState()
{
}

IAppState::~IAppState()
{
}

void IAppState::display()
{
    window->display();      
}

void IAppState::setRenderWindow(window_t& window)
{
    this->window = &window;
}
