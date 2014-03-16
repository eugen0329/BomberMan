#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <vector>
#include "GameStage.hpp"

class Game {
private:
    std::vector<GameStage> stages;
     
public:
    Game();
    virtual ~Game();
};

#endif /* end of include guard: _GAME_HPP_ */
