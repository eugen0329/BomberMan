#include "Game/GameLevel.hpp"

GameLevel::GameLevel() :
window(NULL)
{
}

GameLevel::GameLevel(window_t& window) : 
window(&window)
{
    stageMap.setRenderWindow(window);

    std::string filename("res/WObjectsList.xml");
    TiXmlDocument * xmlFile = alg::openXmlFile(filename);
    TiXmlElement * wObjectIt = alg::getXmlElement(xmlFile, {"WObjects","object"});

    drawableLayers.resize(2);
    
    readObjectsFromXml(wObjectIt);
    delete xmlFile;
} 

GameLevel::~GameLevel()
{
    for (unsigned int i = 0; i < wObjects.size(); i++) {
        delete wObjects[i];
    }
}

void GameLevel::readObjectsFromXml(TiXmlElement* wObjectIt)
{
    while(wObjectIt) {
        std::string className = wObjectIt->Attribute("class");
        if(className == "Player") {
            createActor(new Player(*wObjectIt));
        } else if(className == "Wall") {
            createItem(new Wall(*wObjectIt));
        } else if(className == "Bomb") {
            createItem(new Bomb(*wObjectIt));
        } else {
            std::cout << "ERROR: wrong class name " << className << std::endl;
            continue;
        }

        wObjectIt = wObjectIt->NextSiblingElement("object");
    }
}

void GameLevel::createActor(IWorldsObject* newActor)
{
    setBaseAttributes(newActor);
    newActor->setSignal(alg::createSignal(this, & GameLevel::createItemSignal), "create");
    wObjects.push_back(newActor);
    drawableLayers[1].push_back(newActor);
     
}

void GameLevel::createItem(IWorldsObject* newItem)
{
    setBaseAttributes(newItem);
    wObjects.push_back(newItem);
    drawableLayers[0].push_back(newItem);
}

void GameLevel::setBaseAttributes(IWorldsObject*& wObject)
{
    wObject->setRenderWindow(*window);
    wObject->setMap(stageMap);
    wObject->setWorldsObjectsVector(wObjects);
    wObject->setSignal(alg::createSignal(this, &GameLevel::deleteObjectSignal), "destroying");
}

void GameLevel::handleEvents(const event_t& event)
{
    for (unsigned int i = 0; i < wObjects.size(); i++) {
        wObjects[i]->handleEvents(event);
    }
}

void GameLevel::update(const float& dt)
{
    stageMap.update(dt);

    for (unsigned int i = 0; i < wObjects.size(); i++) {
        wObjects[i]->update(dt);
    }
}

void GameLevel::draw()
{

    stageMap.draw();
    //for (unsigned int i = 0; i < wObjects.size(); i++) {
    //    wObjects[i]->draw();
    //}
    layers_t::iterator lastLayer = drawableLayers.end();

    for(layers_t::iterator layer = drawableLayers.begin(); layer != lastLayer; layer++) {
        wObjects_t::iterator lastWObject = layer->end(); 
        for(wObjects_t::iterator wObject = layer->begin(); wObject != lastWObject; wObject++) {
           (*wObject)->draw();
        }
    }
}

void GameLevel::deleteObjectSignal( IWorldsObject* removable)
{
    deleteObjectFromLayer(removable);
    deleteObjectFromVector(removable);
}

void GameLevel::deleteObjectFromLayer(IWorldsObject* removable)
{
    layers_t::iterator lastLayer = drawableLayers.end();
    for(layers_t::iterator layer = drawableLayers.begin(); layer != lastLayer; layer++) {
        wObjects_t::iterator lObject = std::find( layer->begin(), layer->end(), removable);
        if(lObject != layer->end()) {
            layer->erase(lObject);        
            break;
        }
    }
    //for(unsigned int i = 0; i < drawableLayers.size(); i++) {
    //    wObjects_t::iterator lObject = std::find( drawableLayers[i].begin(), drawableLayers[i].end(), removable);
    //    if(lObject != drawableLayers[i].end()) {
    //        drawableLayers[i].erase(lObject);        
    //        break;
    //    }
    //}
}

void GameLevel::deleteObjectFromVector(IWorldsObject* removable)
{
    wObjects_t::iterator wObject = std::find( wObjects.begin(), wObjects.end(), removable);
    if(wObject != wObjects.end()) {
        delete *wObject;
        wObjects.erase(wObject);        
    }
}

void GameLevel::createItemSignal( IWorldsObject* newWObject)
{
    if( hasCollisions(newWObject)) {
        delete newWObject;
    } else {
        createItem(newWObject);
    }
}

bool GameLevel::hasCollisions(IWorldsObject* verifiable)
{
    wObjects_t::iterator last = wObjects.end();
    for(wObjects_t::iterator it = wObjects.begin(); it != last; ++it) {
        if(  (*it) != verifiable && 
              alg::isCrossing(verifiable->getAttributes(), (*it)->getAttributes())  &&
              (*it)->getAttributes().isSolid() ) {
            return true ;
        }
    }
    return false;
}

void GameLevel::setRenderWindow(window_t* window)
{
    this->window = window;
}
