#ifndef _GAMEISONSTATE_HPP_
#define _GAMEISONSTATE_HPP_

#include <vector>
#include <iostream>
#include "GameStates/IState.hpp"
#include "GameStage.hpp"
#include "Timer.hpp"

class GameIsOnState : public IState {
private:
    //std::vector<GameStage> stages; 
    // renderWindow_t* renderWindowPtr;
    Timer timer;
    GameStage* stage;
protected:
    virtual void draw();
    virtual void update(float);
public:
    GameIsOnState();
    virtual ~GameIsOnState();

   	virtual void load()
   	{
   		stage = new GameStage(renderWindowPtr);
   	}
    
    virtual void processState();
};

#endif /* end of include guard: _GAMEISONSTATE_HPP_ */
