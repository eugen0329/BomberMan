#include "GameStates/StateStack.hpp"


StateStack::StateStack(renderWindow_t & renderWindow) : renderWindowPtr(&renderWindow)
{
}

StateStack::~StateStack()
{
}

StateStack::StateStack()
{
}

int StateStack::push(State* newState)
{
    if(newState != 0) {
        stateStack.push(newState);
        stateStack.top()->setRenderWindow(renderWindowPtr);
    } else {
        return 1;
    }

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

