#ifndef _IAPPSTATE_HPP_
#define _IAPPSTATE_HPP_

#include <functional>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Common/Deferred.hpp"
#include "StateStack.hpp"

typedef sf::Event event_t;
class StateStack;

class IAppState {
protected:
    typedef sf::RenderWindow window_t;
    window_t* window;
    std::function<void(IDeferred*)> pushDeferred;
    StateStack* stateStack;

public:
    IAppState();
    IAppState(window_t&);
    virtual ~IAppState();

    virtual void setWindow(window_t&);
    virtual void load(window_t &window, StateStack&, std::function<void(IDeferred*)>& fn);

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0;
    virtual void display();

};

#endif /* end of include guard: _IAPPSTATE_HPP_ */
