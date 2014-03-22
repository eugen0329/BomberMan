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

void GameStage::update(event_t & event, float dt)
{
    //stageMap.update(dt);
    std::cout << "Before cycle in GameStage::update" << std::endl;
    for (unsigned int i = 0; i < worldsObjects.size(); i++) {
        worldsObjects[i]->update(event, dt);
    }
    std::cout << "---" << std::endl;
}

void GameStage::draw()
{
    std::cout << "Drawing the stage" << std::endl;
    //stageMap.draw();
    for (unsigned int i = 0; i < worldsObjects.size(); i++) {
        worldsObjects[i]->draw();
    }
    std::cout << "---" << std::endl;
}

void GameStage::setRenderWindow(renderWindow_t* renderWindowPtr)
{
    this->renderWindowPtr = renderWindowPtr;
}
