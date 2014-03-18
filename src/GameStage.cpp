#include "GameStage.hpp"

GameStage::GameStage()
{
    stageMap.setSize(20,20);
    worldsObjectV.push_back(new Player(stageMap, worldsObjectV));
}

GameStage::GameStage(std::vector<WorldsObject*> worldsObjectV, GameMap stageMap) : 
    worldsObjectV(worldsObjectV), stageMap(stageMap)
{
}

GameStage::~GameStage()
{
}

GameStage::GameStage(const GameStage& second) :
    worldsObjectV(second.worldsObjectV), stageMap(second.stageMap)
{
}


GameStage& GameStage::operator = (const GameStage& second) 
{
    this->worldsObjectV = second.worldsObjectV;
    this->stageMap = second.stageMap;

    return *this;
}

void GameStage::update()
{
    stageMap.update();
    for (unsigned int i = 0; i < worldsObjectV.size(); i++) {
        worldsObjectV[i]->changeState();
    }
}

void GameStage::draw()
{
    stageMap.draw();
    for (unsigned int i = 0; i < worldsObjectV.size(); i++) {
        worldsObjectV[i]->draw();
    }
}

