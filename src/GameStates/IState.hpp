#ifndef _ISTATE_HPP_
#define _ISTATE_HPP_

#include <SFML/Graphics/RenderWindow.hpp>

typedef sf::Event event_t;

class IState {
protected:
    typedef sf::RenderWindow renderWindow_t;
    renderWindow_t* renderWindowPtr;

    virtual void update(float) = 0;
    virtual void draw() = 0;
    virtual void display();
public:
    IState();
    IState(renderWindow_t *);
    virtual ~IState();

    virtual void setRenderWindow(renderWindow_t*);
    virtual void load() = 0;
    virtual void processState(float) = 0;

};

#endif /* end of include guard: _ISTATE_HPP_ */
