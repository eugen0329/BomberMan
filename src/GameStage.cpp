#include "GameStage.hpp"

GameStage::GameStage()
{
    stageMap.setSize(20,20);
    worldsObjects.push_back(new Player(stageMap, worldsObjects, *renderWindowPtr));
    std::cout << worldsObjects.size();
    exit(1);
}

GameStage::GameStage(GameMap stageMap , std::vector<WorldsObject*> worldsObjects, renderWindow_t * renderWindowPtr) : 
stageMap(stageMap), worldsObjects(worldsObjects), renderWindowPtr(renderWindowPtr)      // Why sequence is important(!!11!1!)
{
}

GameStage::GameStage(renderWindow_t * renderWindowPtr) : 
renderWindowPtr(renderWindowPtr)
{
    stageMap.setSize(20,20);
    worldsObjects.push_back(new Player(stageMap, worldsObjects, *renderWindowPtr));
    std::cout << worldsObjects.size();
    //exit(1);
}

GameStage::~GameStage()
{
}

GameStage::GameStage(const GameStage& second) :
    stageMap(second.stageMap), worldsObjects(second.worldsObjects), renderWindowPtr(second.renderWindowPtr)
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
    //stageMap.update(dt);
    std::cout << "Before cycle in update GameStage" << std::endl;
    for (unsigned int i = 0; i < worldsObjects.size(); i++) {
        std::cout << "GameStage::update" << std::endl;
        worldsObjects[i]->changeState();
    }
}

void GameStage::draw()
{
    //stageMap.draw();
    for (unsigned int i = 0; i < worldsObjects.size(); i++) {
        worldsObjects[i]->draw();
        std::cout << "VV";
    }
}

void GameStage::setRenderWindow(renderWindow_t* renderWindowPtr)
{
    this->renderWindowPtr = renderWindowPtr;
}
