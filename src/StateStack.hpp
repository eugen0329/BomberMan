#ifndef _STATESTACK_HPP_
#define _STATESTACK_HPP_

#include <stack>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameStates/IState.hpp"
#include "IStateStack.hpp"
#include "GameStates/StatesID.hpp"

class StateStack : public IStateStack {
private:
    typedef sf::RenderWindow renderWindow_t;
    renderWindow_t * renderWindowPtr;
    std::stack<IState*> stateStack;
public:
    StateStack(renderWindow_t &);
    ~StateStack();
    StateStack();
    void setRenderWindow(renderWindow_t *renderWindow)
    {
        this->renderWindowPtr = renderWindow;
    }

    int push(IState*);
    int pop();

    inline IState* top() 
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
    void pushStateSignal(IState*);
    void popStateSignal();
};

#endif /* end of include guard: _STATESTACK_HPP_ */
