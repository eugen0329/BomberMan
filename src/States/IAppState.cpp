#include "States/IAppState.hpp"

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

void IAppState::setPushDeferredFn(pushDeferred_t pushDeferred)
{
	this->pushDeferred = pushDeferred;
}
