#ifndef _STATESTACK_HPP_
#define _STATESTACK_HPP_

#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameStates/State.hpp"
#include "GameStates/StatesID.hpp"

class StateStack {
private:
    typedef sf::RenderWindow renderWindow_t;
    renderWindow_t * renderWindowPtr;
    std::stack<State*> stateStack;
public:
    StateStack(renderWindow_t &);
    ~StateStack();
    StateStack();

    int push(State*);
    int pop();

    inline State* getTop() 
    {
        return stateStack.top();
    }
    inline void processTopState() 
    {
        stateStack.top()->processState();
    }
    inline bool isEmpty() const 
    {
        return stateStack.empty();
    }
    inline bool isNotEmpty() const 
    {
        return ! stateStack.empty();
    }
};

#endif /* end of include guard: _STATESTACK_HPP_ */
