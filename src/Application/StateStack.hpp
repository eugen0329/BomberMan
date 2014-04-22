#ifndef _STATESTACK_HPP_
#define _STATESTACK_HPP_

#include <stack>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Common/Interfaces/IAppState.hpp"
#include "Common/StatesID.hpp"

typedef sf::RenderWindow window_t;

class StateStack {
private:

    window_t* window;
    std::stack<IAppState*> stateStack;
public:
    StateStack(window_t &);
    ~StateStack();
    StateStack();
    void setRenderWindow(window_t& window)
    {
        this->window = &window;
    }

    int push(IAppState*);
    int pop();

    inline IAppState* top() 
    {
        return stateStack.top();
    }
    inline bool isEmpty() const 
    {
        return stateStack.empty();
    }
    inline bool isNotEmpty() const 
    {
        return ! stateStack.empty();
    }
    void pushStateSignal(IAppState*);
    void popStateSignal(unsigned int N = 1);
    virtual void clearStack();
};

#endif /* end of include guard: _STATESTACK_HPP_ */
