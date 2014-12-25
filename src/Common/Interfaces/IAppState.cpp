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

void IAppState::setWindow(window_t& window)
{
    this->window = &window;
}

void IAppState::load(window_t &window, StateStack& st, std::function<void(IDeferred*)>& fn)
{
    this->window = &window;
    pushDeferred = fn;
    stateStack = &st;
}

