#ifndef _STATESTACK_HPP_
#define _STATESTACK_HPP_

#include <stack>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>

#include "States/IAppState.hpp"
#include "Common/StatesID.hpp"

#include "Common/Deferred.hpp"

typedef sf::RenderWindow window_t;
class IAppState;

class StateStack {
private:
    window_t* window;
    std::stack<IAppState*> stateStack;
    std::function<void(IDeferred*)> pushDeferred;

public:
    StateStack(window_t &);
    virtual ~StateStack();
    StateStack();

    void load(window_t &window, std::function<void(IDeferred*)>&& fn);

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

    virtual void clearStack();
};

#endif /* end of include guard: _STATESTACK_HPP_ */
