#ifndef _GAMEISONSTATE_HPP_
#define _GAMEISONSTATE_HPP_

#include <vector>
#include "GameStates/State.hpp"
#include "GameStage.hpp"

class GameIsOnState : public State {
private:
    //std::vector<GameStage> stages; 
    GameStage stage;
protected:
    virtual void draw();
    virtual void update();
public:
    GameIsOnState();
    virtual ~GameIsOnState();
    
    inline virtual void processState();
};

#endif /* end of include guard: _GAMEISONSTATE_HPP_ */
