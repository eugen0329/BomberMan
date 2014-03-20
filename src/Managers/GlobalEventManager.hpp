#ifndef _GLOBALEVENTMANAGER_HPP_
#define _GLOBALEVENTMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include "Managers/EventManager.hpp"

class GlobalEventManager : public EventManager {
private:
    typedef sf::RenderWindow renderWindow_t;
    renderWindow_t * pRendeWindow;
public:
    GlobalEventManager();
    GlobalEventManager(renderWindow_t &);
    virtual ~GlobalEventManager();

    void setRenderWindow(renderWindow_t &);
    virtual void processEvents(event_t & );
};


#endif /* end of include guard: _GLOBALEVENTMANAGER_HPP_ */
