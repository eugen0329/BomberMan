#include "GameStage.hpp"

GameStage::GameStage()
{
    //stageMap.setSize(20,20);
    stageMap.setRenderWindow(*pRenderWindow);
    worldsObjects.push_back(new Player(stageMap, worldsObjects, *pRenderWindow));
}

GameStage::GameStage(GameMap stageMap , std::vector<WorldsObject*> worldsObjects, renderWindow_t * pRenderWindow) : 
stageMap(stageMap), worldsObjects(worldsObjects), pRenderWindow(pRenderWindow)      // Why sequence is important(!!11!1!)
{
}

GameStage::GameStage(renderWindow_t * pRenderWindow) : 
pRenderWindow(pRenderWindow)
{
    //stageMap.setSize(20,20);
    stageMap.setRenderWindow(*pRenderWindow);
    worldsObjects.push_back(new Player(stageMap, worldsObjects, *pRenderWindow));
}

GameStage::~GameStage()
{
}

GameStage::GameStage(const GameStage& second) :
    stageMap(second.stageMap), worldsObjects(second.worldsObjects), pRenderWindow(second.pRenderWindow)
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
    //
    for (unsigned int i = 0; i < worldsObjects.size(); i++) {
        worldsObjects[i]->update(dt);
    }

}

void GameStage::draw()
{

    stageMap.draw();
    for (unsigned int i = 0; i < worldsObjects.size(); i++) {
        worldsObjects[i]->draw();
    }

}

void GameStage::setRenderWindow(renderWindow_t* pRenderWindow)
{
    this->pRenderWindow = pRenderWindow;
}
