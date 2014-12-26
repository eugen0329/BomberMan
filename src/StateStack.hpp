#ifndef _STATESTACK_HPP_
#define _STATESTACK_HPP_

#include <stack>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Common/BasicTypes.hpp"
#include "States/IAppState.hpp"

typedef sf::RenderWindow window_t;
class IAppState;

class StateStack {
    friend class Application;
    std::stack<IAppStatePtr> stack;


public:
    StateStack();
    ~StateStack();

    std::function<void(IAppStatePtr)> push;

    inline IAppStatePtr top() { return stack.top(); }
    inline void pop() { stack.pop(); }
    inline bool empty() const { return stack.empty(); }
    inline bool notEmpty() const { return stack.empty(); }
    void clear();
};

#endif /* end of include guard: _STATESTACK_HPP_ */
