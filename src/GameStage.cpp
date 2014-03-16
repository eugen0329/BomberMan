#include "GameStage.hpp"

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
