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

    pushDeferred = [&](dererredAct&& fn) { deferredQueue.push(fn);};

    scene.setFnInit([&](IWObjectPtr& ob) {
        ob->setWindow(window);
        ob->setWorldObjects(scene.wObjects);
        ob->setFnPushDeferred(pushDeferred);  
    });

    readObjectsFromXml(wObjectIt);

    delete xmlFile;
} 

GameLevel::~GameLevel()
{
}

void GameLevel::readObjectsFromXml(TiXmlElement* xml)
{
    for (TiXmlElement* it = xml; it != NULL; it = it->NextSiblingElement("object")) {

        std::string className = it->Attribute("class");
        if(className == "Player") {
            scene.add(std::make_shared<Player>(*it), 1);
        } else if(className == "Wall") {
            scene.add(std::make_shared<Wall>(*it), 0);
        } else if(className == "Slug") {
            scene.add(std::make_shared<Slug>(*it, Vec2<float>(250, 50)), 0); 
        } else {
            std::cerr << "ERROR: wrong class name " << className << std::endl;
        }
    }
}

void GameLevel::handleEvents(const event_t& event)
{
    scene.handleEvents(event);
}

void GameLevel::update(const float& dt)
{
    scene.update(dt);

    while(! deferredQueue.empty()) {
        deferredQueue.front()(&scene);
        deferredQueue.pop();
    }
}

void GameLevel::draw()
{
    levelMap.draw();
    scene.draw();
}

void GameLevel::setWindow(window_t* window)
{
    this->window = window;
}
