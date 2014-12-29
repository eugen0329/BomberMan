#include "Game/GameLevel.hpp"

GameLevel::GameLevel() : window(NULL)
{
}

GameLevel::GameLevel(window_t& window) : window(&window)
{

    levelMap.setWindow(window);
    TiXmlDocument * xmlFile = alg::openXmlFile("res/WObjectsList.xml");
    defaultWObjAttr = alg::openXmlFile("res/DefaultWObjAttr.xml");

    loadScene();
    loadObjects(alg::getXmlElem(xmlFile, {"WObjects","object"}));
    loadWidgets();
    loadEnemyGenerator();


    delete xmlFile;
} 

void GameLevel::loadScene()
{
    pushDeferred = [&](dererredAct&& fn) { deferredQueue.push(fn);};

    scene.setFnInit([&](IWObjectPtr& ob) {
        ob->setWindow(*window);
        ob->setWorldObjects(scene.wObjects);
        ob->setFnPushDeferred(pushDeferred);  
    });
    int enemyId = 2;
    scene.notifyRemoval = [&, enemyId](int groupID) {if(groupID == 2) increaseScore();};
}

void GameLevel::loadWidgets()
{
    scoreWidget.setFont(conf::defaultFont);
    scoreWidget.setColor(sf::Color::Blue);
    scoreWidget.setStyle(sf::Text::Bold);
    scoreWidget.setPosition(window->getSize().x * 0.9, 0 );  
    scoreWidget.setString("0");
}

void GameLevel::loadEnemyGenerator()
{
    createEnemyTimer = alg::randInRange(1.f, 3.f);
    timePassed = 0.f;
    score = 0;

    slugHoles.push_back(Vec2<float>(250, 50));
    slugHoles.push_back(Vec2<float>(250, 400));
    slugHoles.push_back(Vec2<float>(50, 400));
}

void GameLevel::increaseScore()
{
    int score = alg::parseInt(scoreWidget.getString().toAnsiString()) + 1;
    scoreWidget.setString(std::to_string(score));
}

GameLevel::~GameLevel()
{
    delete defaultWObjAttr;
}

void GameLevel::loadObjects(TiXmlElement* xml)
{
    for (TiXmlElement* it = xml; it != NULL; it = it->NextSiblingElement("object")) {

        std::string className = it->Attribute("class");
        if(className == "Player") {
            scene.add(std::make_shared<Player>(*it), 1);
        } else if(className == "Wall") {
            scene.add(std::make_shared<Wall>(*it), 0);
        } else if(className == "Slug") {
           //scene.add(std::make_shared<Slug>(*it, Vec2<float>(250, 50)), 0); 
        } else {
            std::cerr << "ERROR: wrong class name " << className << std::endl;
        }
    }
}

void GameLevel::handleEvents(const event_t& event)
{
    scene.handleEvents(event);
}

int GameLevel::update(const float& dt)
{
    timePassed += dt;
    if(timePassed >= createEnemyTimer) {
        createEnemy();
        timePassed = 0.f;
        createEnemyTimer = alg::randInRange(0.5f, 1.5f);
    }

    scene.update(dt);

    if(! deferredQueue.empty()) {
        while(! deferredQueue.empty()) {
            deferredQueue.front()(&scene);
            deferredQueue.pop();
        }        
    }
    if(playerIsDead()) return 1;
    return 0;
}

void GameLevel::createEnemy()
{
    TiXmlElement* elem = alg::getXmlElem(defaultWObjAttr, {"WObjects", "slug"});

    Vec2<float> pos = *alg::randElem(slugHoles.begin(), slugHoles.end());
    int layer = 0;
    scene.add( std::make_shared<Slug>(*elem, pos), layer);
}

bool GameLevel::playerIsDead()
{
    using namespace std;
    WObjects objVec = scene.wObjects;
    WObjects::iterator player = find_if(begin(objVec), end(objVec), [](IWObjectPtr obj)->bool{return obj->getAttr().groupID == 1;});
    if(player == objVec.end()) return true;
    return false;
}

void GameLevel::draw()
{
    levelMap.draw();
    scene.draw();
    window->draw(scoreWidget);
}

void GameLevel::setWindow(window_t* window)
{
    this->window = window;
}
