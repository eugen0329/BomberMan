#include "StateStack.hpp"


StateStack::StateStack(window_t & window) : window(&window)
{
}

StateStack::~StateStack()
{
}

StateStack::StateStack()
{
}

int StateStack::push(IAppState* newState)
{
    stateStack.push(newState);
    //stateStack.top()->setRenderWindow(*window);
    stateStack.top()->load(*window, *this, pushDeferred);

    return 0;
}

int StateStack::pop()
{
    if(stateStack.empty()) {
        return 1;
    } else {
        delete stateStack.top();
        stateStack.pop();
        std::cerr << "pop";
    }
    
    return 0;
}

void StateStack::clearStack()
{
    for(unsigned int i = 0; i < stateStack.size(); i++) {
        delete stateStack.top();
        stateStack.pop();
    }
}

void StateStack::load(window_t &window, std::function<void(IDeferred*)>&& fn)
{
    this->window = &window;
    pushDeferred = fn;
}
