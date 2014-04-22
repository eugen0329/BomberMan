#ifndef _IEVENTMANAGER_HPP_
#define _IEVENTMANAGER_HPP_

#include <SFML/Graphics.hpp>

class IEventManager {
private:
protected:
    typedef sf::Event event_t;
public:
    IEventManager();
    ~IEventManager();

    virtual void handleEvents(const event_t &) = 0;
};


#endif /* end of include guard: _IEVENTMANAGER_HPP_ */
