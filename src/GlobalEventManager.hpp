#ifndef _GLOBALEVENTMANAGER_HPP_
#define _GLOBALEVENTMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include "Common/Interfaces/IEventManager.hpp"

class GlobalEventManager : public IEventManager {
private:
    typedef sf::RenderWindow window_t;
    window_t * window;
public:
    GlobalEventManager();
    GlobalEventManager(window_t &);
    virtual ~GlobalEventManager();

    void setWindow(window_t &);
    virtual void handleEvents(const event_t & );
};


#endif /* end of include guard: _GLOBALEVENTMANAGER_HPP_ */
