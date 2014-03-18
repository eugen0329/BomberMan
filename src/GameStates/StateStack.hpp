#ifndef _STATESTACK_HPP_
#define _STATESTACK_HPP_

#include "GameStates/State.hpp"

class StateStack {
private:
    typedef struct {
        StateStack* top;
        StateStack* prev;
        
        State* state;
    } contents_t;    

    contents_t contents;
public:
    StateStack();
    ~StateStack();

    int push();
    int pop();
    const StateStack getTop() const;
    
    bool isEmpty() const;
    
};

#endif /* end of include guard: _STATESTACK_HPP_ */
