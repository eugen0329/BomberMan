#ifndef _GLOBALEVENTMANAGER_HPP_
#define _GLOBALEVENTMANAGER_HPP_

#include <SFML/Graphics.hpp>

#include "Common/BasicTypes.hpp"

class GlobalEventManager {
private:
    window_t * window;
public:
    GlobalEventManager();
    GlobalEventManager(window_t &);
    virtual ~GlobalEventManager();

    void setWindow(window_t &);
    virtual void handleEvents(const event_t & );
};


#endif /* end of include guard: _GLOBALEVENTMANAGER_HPP_ */
