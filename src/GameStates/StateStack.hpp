#ifndef _STATESTACK_HPP_
#define _STATESTACK_HPP_

#include "GameStates/State.hpp"
#include <stack>

class StateStack {
private:

    std::stack<State*> stateStack;
public:
    StateStack();
    ~StateStack();

    int push(State*);
    int pop();
    
    bool isEmpty() const;
    
};

#endif /* end of include guard: _STATESTACK_HPP_ */
