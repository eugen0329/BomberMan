#ifndef _ISTATESTACK_HPP_
#define _ISTATESTACK_HPP_

#include "GameStates/IState.hpp"

class IStateStack {
private:
    
public:
    IStateStack();
    virtual ~IStateStack();

    virtual void pushStateSignal(IState*) = 0;
    virtual void popStateSignal(unsigned int) = 0;
    virtual void clearStack() = 0;
};


#endif /* end of include guard: _ISTATESTACK_HPP_ */
