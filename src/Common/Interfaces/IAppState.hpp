#ifndef _IAPPSTATE_HPP_
#define _IAPPSTATE_HPP_

#include <SFML/Graphics/RenderWindow.hpp>

typedef sf::Event event_t;

class IAppState {
protected:
    typedef sf::RenderWindow window_t;
    window_t* window;

public:
    IAppState();
    IAppState(window_t&);
    virtual ~IAppState();

    virtual void setRenderWindow(window_t&);
    virtual void load() = 0;

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0;
    virtual void display();

};

#endif /* end of include guard: _IAPPSTATE_HPP_ */
