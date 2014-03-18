#include "GameStates/StateStack.hpp"


StateStack::StateStack()
{
    if(this->contents.top == 0) {
        this->contents.top = this;
    }
    this->contents.prev = 0;
    this->contents.state = 0;
    

}

StateStack::~StateStack()
{
}

int StateStack::push()
{
    return 0;
}

int StateStack::pop()
{
    return 0;
}

bool StateStack::isEmpty() const 
{
    if(this->contents.top == 0) {
        return true;
    }

    return false;
}

const StateStack StateStack::getTop() const
{
    return *(this->contents.top);
}
