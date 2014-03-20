#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <SFML/Graphics.hpp>

class Timer {
private:
    typedef sf::Clock timer_t;
    timer_t timer;
public:
    Timer() {}
    ~Timer() {}
    inline float getElapsedTime()
    {
        float dt = timer.getElapsedTime().asMilliseconds();
        timer.restart();
        return dt;
 
    }
    inline void restart()
    {
        timer.restart();
    }
};


#endif /* end of include guard: _TIMER_HPP_ */
