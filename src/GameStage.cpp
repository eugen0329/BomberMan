#include "GameStage.hpp"

GameStage::GameStage()
{
    stageMap.setSize(20,20);
    worldsObjectV.push_back(new Player(stageMap, worldsObjectV, *renderWindowPtr));
}

GameStage::GameStage(GameMap stageMap , std::vector<WorldsObject*> worldsObjectV, renderWindow_t * renderWindowPtr) : 
stageMap(stageMap), worldsObjectV(worldsObjectV), renderWindowPtr(renderWindowPtr)      // Why sequence is important(!!11!1!)
{
}

GameStage::GameStage(renderWindow_t * renderWindowPtr) : 
renderWindowPtr(renderWindowPtr)
{
}

GameStage::~GameStage()
{
}

GameStage::GameStage(const GameStage& second) :
    stageMap(second.stageMap), worldsObjectV(second.worldsObjectV), renderWindowPtr(second.renderWindowPtr)
{
}


//GameStage& GameStage::operator = (const GameStage& second) 
//{
//    this->worldsObjectV = second.worldsObjectV;
//    this->stageMap = second.stageMap;
//    this->ren
//
//    return *this;
//}

void GameStage::update(float dt)
{
    stageMap.update(dt);
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

void GameStage::setRenderWindow(renderWindow_t* renderWindowPtr)
{
    this->renderWindowPtr = renderWindowPtr;
}