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
