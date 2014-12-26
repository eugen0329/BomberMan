#include "StateStack.hpp"

StateStack::~StateStack()
{
}

StateStack::StateStack()
{
}

void StateStack::clear()
{
    while(! stack.empty()) {
        stack.pop();
    }
}
