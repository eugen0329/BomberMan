#include "Application/StateStack.hpp"


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
    stateStack.top()->setRenderWindow(*window);
    stateStack.top()->load();

    return 0;
}

int StateStack::pop()
{
    if(stateStack.empty()) {
        return 1;
    } else {
        delete stateStack.top();
        stateStack.pop();
    }
    
    return 0;
}

void StateStack::pushStateSignal(IAppState* newState)
{
    stateStack.push(newState);
    stateStack.top()->setRenderWindow(*window);
    stateStack.top()->load();
}

void StateStack::popStateSignal(unsigned int N)
{
    unsigned int i = 0;
    while(i < N && ! stateStack.empty()) {
        delete stateStack.top();
        stateStack.pop();
        i++;
    }
}
void StateStack::clearStack()
{
    for(unsigned int i = 0; i < stateStack.size(); i++) {
        delete stateStack.top();
        stateStack.pop();
    }
}
