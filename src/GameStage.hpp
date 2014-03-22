#ifndef _GAMESTAGE_HPP_
#define _GAMESTAGE_HPP_

#include <vector>
#include <iostream>



#include "WorldsObjects/Player.hpp"
#include "GameMap.hpp"
#include "WorldsObjects/WorldsObject.hpp"

typedef sf::Event event_t;

class GameStage {
private:
    typedef sf::RenderWindow renderWindow_t;

    GameMap stageMap;
    std::vector<WorldsObject*> worldsObjects;
    renderWindow_t* renderWindowPtr;
public:
    GameStage(GameMap, std::vector<WorldsObject*>, renderWindow_t*);
    GameStage();
    GameStage(renderWindow_t * );
    GameStage(const GameStage&);
    ~GameStage();

	void setRenderWindow(renderWindow_t*);
    void update(float);
    void draw();
    //GameStage& operator = (const GameStage&);
};

#endif /* end of include guard: _GAMESTAGE_HPP_ */
