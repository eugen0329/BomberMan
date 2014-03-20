#ifndef _EVENTMANAGER_HPP_
#define _EVENTMANAGER_HPP_

#include <SFML/Graphics.hpp>

class EventManager {
private:
protected:
    typedef sf::Event event_t;
public:
    EventManager();
    ~EventManager();

    virtual void processEvents(event_t &) = 0;
};


#endif /* end of include guard: _EVENTMANAGER_HPP_ */
