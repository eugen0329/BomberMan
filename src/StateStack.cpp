#include "StateStack.hpp"


StateStack::StateStack(renderWindow_t & renderWindow) : renderWindowPtr(&renderWindow)
{
}

StateStack::~StateStack()
{
}

StateStack::StateStack()
{
}

int StateStack::push(IState* newState)
{
    stateStack.push(newState);
    stateStack.top()->setRenderWindow(renderWindowPtr);
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

void StateStack::pushStateSignal(IState* newState)
{
    stateStack.push(newState);
    stateStack.top()->setRenderWindow(renderWindowPtr);
    stateStack.top()->load();
}

void StateStack::popStateSignal()
{
    if(stateStack.empty()) {
    } else {
        delete stateStack.top();
        stateStack.pop();
    }
}
