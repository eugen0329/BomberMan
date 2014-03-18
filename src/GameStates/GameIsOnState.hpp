#ifndef _GAMEISONSTATE_HPP_
#define _GAMEISONSTATE_HPP_

#include "GameStates/State.hpp"

class GameIsOnState : public State {
protected:
    virtual void draw();
    virtual void update();
public:
    GameIsOnState();
    virtual ~GameIsOnState();
    
    inline virtual void processState();
};

#endif /* end of include guard: _GAMEISONSTATE_HPP_ */
