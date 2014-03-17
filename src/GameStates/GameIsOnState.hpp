#ifndef _GAMEISONSTATE_HPP_
#define _GAMEISONSTATE_HPP_

#include "State.hpp"

class GameIsOnState : public State {
private:
    /* data */
public:
    GameIsOnState();
    virtual ~GameIsOnState();
    
    virtual void draw();
    virtual void update();
};

#endif /* end of include guard: _GAMEISONSTATE_HPP_ */
