#include "Game/GameLevel.hpp"

GameLevel::GameLevel() :
window(NULL)
{
}

GameLevel::GameLevel(window_t& window) : 
window(&window)
{
    levelMap.setRenderWindow(window);

    std::string filename("res/WObjectsList.xml");
    TiXmlDocument * xmlFile = alg::openXmlFile(filename);
    TiXmlElement  * wObjectIt = alg::getXmlElement(xmlFile, {"WObjects","object"});

    layers.resize(2);
    
    readObjectsFromXml(wObjectIt);
    delete xmlFile;
} 

GameLevel::~GameLevel()
{
}

void GameLevel::readObjectsFromXml(TiXmlElement* xml)
{
    for (TiXmlElement* it = xml; it; it = it->NextSiblingElement("object")) {

        std::string className = it->Attribute("class");
        if(className == "Player") {
            createActor(std::make_shared<Player>(*it));
        } else if(className == "Wall") {
            createItem(std::make_shared<Wall>(*it));
        } else {
            std::cerr << "ERROR: wrong class name " << className << std::endl;

        }
    }
}

void GameLevel::createActor(pWObject_t newActor)
{
    setBaseAttributes(newActor);
    newActor->setSignal(alg::createSignal(this, & GameLevel::createItemSignal), "create");
    wObjects.push_back(newActor);
    layers[1].push_back(newActor);
     
}

void GameLevel::createItem(pWObject_t newItem)
{
    setBaseAttributes(newItem);
    newItem->setSignal(alg::createSignal(this, & GameLevel::createItemSignal), "create");
    wObjects.push_back(newItem);
    layers[0].push_back(newItem);
}

void GameLevel::setBaseAttributes(pWObject_t& wObject)
{
    wObject->setRenderWindow(*window);
    wObject->setMap(levelMap);
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
    levelMap.update(dt);

    for(wObjects_t::iterator wObject = wObjects.begin(); wObject != wObjects.end(); wObject++) {
       (*wObject)->update(dt);
    }
    for(wObjects_t::iterator wObject = wObjects.begin(); wObject != wObjects.end(); wObject++) {
       (*wObject)->handleCollisions();
    }

    while(! signals.empty()) {
        if(signals.front().name == "delete") {
            deleteObjectFromLayer(signals.front().operand);
            deleteObjectFromVector(signals.front().operand);
        } else if(signals.front().name == "create") {
            createItem(signals.front().operand);
        }
        signals.pop();
    }
}

void GameLevel::draw()
{

    levelMap.draw();

    layers_t::iterator lastLayer = layers.end();

    for(layers_t::iterator layer = layers.begin(); layer != lastLayer; layer++) {
        wObjects_t::iterator lastWObject = layer->end(); 
        for(wObjects_t::iterator wObject = layer->begin(); wObject != lastWObject; wObject++) {
           (*wObject)->draw();
        }
    }
}

void GameLevel::deleteObjectSignal(pWObject_t removable)
{
    signals.push(Signal(removable, "delete"));
}

void GameLevel::deleteObjectFromLayer(pWObject_t removable)
{
    layers_t::iterator lastLayer = layers.end();
    for(layers_t::iterator layer = layers.begin(); layer != lastLayer; layer++) {
        wObjects_t::iterator lObject = std::find( layer->begin(), layer->end(), removable);
        if(lObject != layer->end()) {
            layer->erase(lObject);        
            break;
        }
    }
}

void GameLevel::deleteObjectFromVector(pWObject_t removable)
{
    wObjects_t::iterator wObject = std::find( wObjects.begin(), wObjects.end(), removable);
    if(wObject != wObjects.end()) {
        wObjects.erase(wObject);        
    }
}

void GameLevel::createItemSignal( pWObject_t newWObject)
{
    signals.push(Signal(newWObject, "create"));
}

void GameLevel::setRenderWindow(window_t* window)
{
    this->window = window;
}
