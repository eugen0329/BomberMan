#ifndef _IAPPSTATE_HPP_
#define _IAPPSTATE_HPP_

#include <functional>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Common/BasicTypes.hpp"
#include "StateStack.hpp"


class StateStack;

class IAppState {
protected:
    window_t* window;
    pushDeferred_t pushDeferred;

public:
    IAppState();
    IAppState(window_t&);
    virtual ~IAppState();

    virtual void setWindow(window_t&);

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0;
    virtual void display();
    virtual void setPushDeferredFn(pushDeferred_t);
};

#endif /* end of include guard: _IAPPSTATE_HPP_ */
