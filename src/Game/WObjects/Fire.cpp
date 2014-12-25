#include "Game/WObjects/Fire.hpp"

Fire::Fire()
{
}

Fire::Fire(const Vec2<float>& pos, int groupId, STYLE style)
{
    TiXmlDocument * xmlFile = alg::openXmlFile("./res/FireAnimation.xml");
    xmlElem_t * animationList = alg::getXmlElem(xmlFile, {"fire", "animations"});
    xmlElem_t * xmlAttr;

    if(style == STYLE::FLAME) {
       xmlAttr = alg::getXmlElem(xmlFile, {"fire"});
    } else if(style == STYLE::BLOW) {
        xmlAttr = alg::getXmlElem(xmlFile, {"blow"});
    } else {
        std::cerr << "err";
    }

    attr.pos.x = pos.x;
    attr.pos.y = pos.y;
    attr.groupID = groupId;

    load(*xmlAttr);

    animationManager.setSprite(attr.sprite);
    animationManager.loadAnimations(*animationList);

    animationManager.updateCurrentAnimation(0);
    delete xmlFile;
}

void Fire::load(xmlElem_t& elem)
{
    attr.solid = false;
    attr.harmful = true;

    attr.lifeTime = alg::parseFloat(elem.Attribute("lifeTime"));
    attr.actLifeTime = 0.0;
    attr.damage = alg::parseInt(elem.Attribute("damage"));

    attr.width = alg::parseInt(elem.Attribute("width"));
    attr.heigth = alg::parseInt(elem.Attribute("heigth"));
    attr.origin.x =  alg::parseInt(elem.Attribute("origX"));
    attr.origin.y  = alg::parseInt(elem.Attribute("origY"));

    attr.texture.loadFromFile(elem.Attribute("texture"));
    attr.sprite.setTexture(attr.texture);
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
    attr.sprite.setOrigin(attr.origin.x, attr.origin.y);
}

Fire::~Fire()
{
}

void Fire::handleEvents(const event_t&)
{
} 

void Fire::update(const float& dt) 
{ 
    attr.actLifeTime += dt;
    animationManager.updateCurrentAnimation(dt);
 
    //std::cout <<  attr.actLifeTime;
    if(attr.actLifeTime >= attr.lifeTime) 
    {
        pushDeferred([this](DrawableScene * scene) {
            scene->remove(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
        });
        //destroyingSignal(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
    }
}


void Fire::draw()
{
    window->draw(attr.sprite);
}

void Fire::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    } else if(signalName == "create") {
        this->createSignal = *delegate;        
    }
}


void Fire::setWorldObjects(WObjects& wObjects)
{
    this->wObjects = &wObjects;
}