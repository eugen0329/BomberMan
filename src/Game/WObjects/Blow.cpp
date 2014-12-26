#include "Game/WObjects/Blow.hpp"

Blow::Blow()
{
}

Blow::Blow(const Vec2<float>& pos, int groupId, STYLE style)
{
    TiXmlDocument * xmlFile = alg::openXmlFile("./res/BlowAnimation.xml");
    
    xmlElem_t * xmlAttr;
    xmlElem_t * animationList;

    if(style == STYLE::FLAME) {
       xmlAttr = alg::getXmlElem(xmlFile, {"fire"});
       animationList = alg::getXmlElem(xmlFile, {"fire", "animations"});
    } else if(style == STYLE::BLOW) {
        xmlAttr = alg::getXmlElem(xmlFile, {"blow"});
        animationList = alg::getXmlElem(xmlFile, {"blow", "animations"});
    } else if(style == STYLE::SLUG_BLOW) {
        xmlAttr = alg::getXmlElem(xmlFile, {"slugblow"});
        animationList = alg::getXmlElem(xmlFile, {"slugblow", "animations"});
    } else  {
        std::cerr << "err";
    }

    attr.pos.x = pos.x;
    attr.pos.y = pos.y;
    attr.groupID = 0;

    load(*xmlAttr);

    animationManager.setSprite(attr.sprite);
    animationManager.loadAnimations(*animationList);
    
    delete xmlFile;
}

void Blow::load(xmlElem_t& elem)
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

Blow::~Blow()
{
}

void Blow::handleEvents(const event_t&)
{
} 

void Blow::update(const float& dt) 
{ 
    attr.actLifeTime += dt;
    animationManager.updateCurrentAnimation(dt);
 
    if(attr.actLifeTime >= attr.lifeTime) 
    {
        pushDeferred([this](DrawableScene * scene) {
            scene->remove(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
        });
    }
}

void Blow::draw()
{
    window->draw(attr.sprite);
}

void Blow::setWorldObjects(WObjects& wObjects)
{
    this->wObjects = &wObjects;
}