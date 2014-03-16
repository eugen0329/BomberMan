#ifndef _GAMESTAGE_HPP_
#define _GAMESTAGE_HPP_

#include <vector>

#include "GameMap.hpp"
#include "WorldsObject.hpp"

class GameStage {
private:
    std::vector<WorldsObject*> worldsObjectV; 
    GameMap stageMap;
public:
    GameStage(std::vector<WorldsObject*>, GameMap);
    GameStage(const GameStage&);
    ~GameStage();

    GameStage& operator = (const GameStage&);
};

#endif /* end of include guard: _GAMESTAGE_HPP_ */
