#include "Game/GameLevel.hpp"

GameLevel::GameLevel() : window(NULL)
{
}

GameLevel::GameLevel(window_t& window) : window(&window)
{
    levelMap.setWindow(window);
    std::string filename("res/WObjectsList.xml");
    TiXmlDocument * xmlFile = alg::openXmlFile(filename);
    TiXmlElement  * wObjectIt = alg::getXmlElem(xmlFile, {"WObjects","object"});

    pushDeferred = [&](dererredAct&& fn) { defSt.push(fn);};

    scene.setFnInit([&](IWObjectPtr& ob) {
        Delegate delegate;
        delegate.bind(this, & GameLevel::deleteObjectSignal);
        
        ob->setWindow(window);
        ob->setWorldObjects(scene.wObjects);
        ob->setSignal(&delegate, "destroying");
        ob->setFnPushDeferred(pushDeferred);  
        delegate.bind(this, & GameLevel::createItemSignal);
        ob->setSignal(&delegate, "create");   
    });
    readObjectsFromXml(wObjectIt);

    delete xmlFile;
} 

GameLevel::~GameLevel()
{
    while(! signals.empty()) signals.pop();
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


void GameLevel::setBaseAttributes(IWObjectPtr& wObject)
{
    Delegate delegate;
    delegate.bind(this, & GameLevel::deleteObjectSignal);

    wObject->setWindow(*window);
    wObject->setWorldObjects(wObjects);
    wObject->setSignal(&delegate, "destroying");
    wObject->setFnPushDeferred(pushDeferred);
    
    //auto s = std::bind<void>([&](dererredAct&& fn) { defSt.push(fn);});
    
    //auto f = [](DrawableScene& scene) {
    //    scene.add(std::make_shared<IWObjectPtr>(new Bomb))
    //};
}


void GameLevel::createActor(IWObjectPtr newActor)
{
    Delegate delegate;
    delegate.bind(this, & GameLevel::createItemSignal);

    setBaseAttributes(newActor);
    newActor->setSignal(&delegate, "create");
    scene.add(newActor, 1);
    //wObjects.push_back(newActor);
    //layers[1].push_back(newActor);
     
}

void GameLevel::createItem(IWObjectPtr newItem)
{
    Delegate delegate;
    delegate.bind(this, & GameLevel::createItemSignal);

    setBaseAttributes(newItem);
    newItem->setSignal(&delegate, "create");

    scene.add(newItem, 0);
    //wObjects.push_back(newItem);
    //layers[0].push_back(newItem);
}



void GameLevel::handleEvents(const event_t& event)
{
    scene.handleEvents(event);
    //for (unsigned int i = 0; i < wObjects.size(); i++) {
    //    wObjects[i]->handleEvents(event);
    //}
}

void GameLevel::update(const float& dt)
{
    //levelMap.update(dt);
    scene.update(dt);

    for(WObjects::iterator wObject = wObjects.begin(); wObject != wObjects.end(); wObject++) {
       (*wObject)->update(dt);
    }

    while(! defSt.empty()) {
        defSt.top()(&scene);
        defSt.pop();
    }
    while(! signals.empty()) {
        if(signals.front().name == "delete") {
            scene.remove(signals.front().operand);
            //deleteObjectFromLayer(signals.front().operand);
            //deleteObjectFromVector(signals.front().operand);
        } else if(signals.front().name == "create") {
            createItem(signals.front().operand);
        }
        signals.pop();
    }
}

void GameLevel::draw()
{
    levelMap.draw();
    scene.draw();
}


void GameLevel::deleteObjectFromLayer(IWObjectPtr removable)
{
    layers_t::iterator lastLayer = layers.end();
    for(layers_t::iterator layer = layers.begin(); layer != lastLayer; layer++) {
        WObjects::iterator lObject = std::find( layer->begin(), layer->end(), removable);
        if(lObject != layer->end()) {
            layer->erase(lObject);        
            break;
        }
    }
}

void GameLevel::deleteObjectFromVector(IWObjectPtr removable)
{
    WObjects::iterator wObject = std::find( wObjects.begin(), wObjects.end(), removable);
    if(wObject != wObjects.end()) {
        wObjects.erase(wObject);        
    }
}

void GameLevel::setWindow(window_t* window)
{
    this->window = window;
}







void GameLevel::deleteObjectSignal(IWObjectPtr removable)
{
    signals.push(Signal(removable, "delete"));
}

void GameLevel::createItemSignal( IWObjectPtr newWObject)
{
    signals.push(Signal(newWObject, "create"));
}
