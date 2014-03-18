#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <SFML/Graphics/RenderWindow.hpp>

class State {
protected:
    typedef sf::RenderWindow renderWindow_t;
    renderWindow_t* renderWindowPtr;

    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void display();
public:
    State();
    State(renderWindow_t *);
    virtual ~State();

    virtual void setRenderWindow(renderWindow_t*);
    virtual void processState() = 0;

};

#endif /* end of include guard: _STATE_HPP_ */
