#ifndef _GAMESTAGE_HPP_
#define _GAMESTAGE_HPP_

#include <vector>

#include "WorldsObjects/Player.hpp"
#include "GameMap.hpp"
#include "WorldsObjects/WorldsObject.hpp"

class GameStage {
private:
    std::vector<WorldsObject*> worldsObjectV; 
    GameMap stageMap;
public:
    GameStage(std::vector<WorldsObject*>, GameMap);
    GameStage();
    GameStage(const GameStage&);
    ~GameStage();

    void update();
    void draw();
    GameStage& operator = (const GameStage&);
};

#endif /* end of include guard: _GAMESTAGE_HPP_ */
