#include "Game/WObjects/Fire.hpp"

Fire::Fire()
{
}

void Fire::setWorldObjects(wObjects_t& wObjects)
{
    this->wObjects = &wObjects;
}

Fire::Fire(const IWorldsObject::Attributes& parAttr, Vec2<float> offset)
{    
    TiXmlDocument * xmlFile = alg::openXmlFile("./res/FireAnimation.xml");
    xmlElem_t * animationList = alg::getXmlElement(xmlFile, {"fire"});



    attr.texture.loadFromFile("./res/Animations/Fire.gif");
    attr.sprite.setTexture(attr.texture);
    animationManager.setSprite(attr.sprite);
    animationManager.loadAnimations(*animationList);


    attr.harmful = true; 
    attr.solid = false;

    attr.groupID = parAttr.groupID;

    attr.damage = 20;
    attr.lifeTime = 1.5;
    attr.actLifeTime = 0.0;

    attr.width = 32;
    attr.heigth = 32;

    attr.origin.x =  16;
    attr.origin.y  = 16;

    attr.sprite.setOrigin(attr.origin.x, attr.origin.y);
    attr.pos.x = parAttr.pos.x;
    attr.pos.y = parAttr.pos.y;

    attr.pos += offset;

    attr.sprite.setPosition(attr.pos.x, attr.pos.y );


    animationManager.updateCurrentAnimation(0);
    delete xmlFile;
}
void Fire::loadAttr(xmlElem_t& elem)
{

}

Fire::Fire(xmlElem_t& xmlElement)
{    
	Fire::Initializer initializer(xmlElement, attr);

    if(initializer.load()) {
        exit(1);
    }    

}

Fire::Fire(const IWorldsObject::Attributes& parAttr)
{    
    TiXmlDocument * xmlFile = alg::openXmlFile("./res/FireAnimation.xml");
    xmlElem_t * animationList = alg::getXmlElement(xmlFile, {"blow"});

    attr.texture.loadFromFile("./res/Animations/Blow.gif");
    attr.sprite.setTexture(attr.texture);
    animationManager.setSprite(attr.sprite);
    animationManager.loadAnimations(*animationList);

    attr.harmful = true; 
    attr.solid = false;

    attr.groupID = parAttr.groupID;

    attr.damage = 20;
    attr.lifeTime = 1;
    attr.actLifeTime = 0.0;

    attr.width = 32;
    attr.heigth = 32;

    attr.origin.x =  16;
    attr.origin.y  = 16;

    attr.pos.x = parAttr.pos.x;
    attr.pos.y = parAttr.pos.y;
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
    animationManager.updateCurrentAnimation(0);
    delete xmlFile;
}

void Fire::addCollision(Collision)
{
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
        destroyingSignal(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
    }
}

void Fire::checkCollisions()
{
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

int Fire::Initializer::load() const
{
    if(attr == NULL) {
        return 1; 
    }


    if(std::string(element->Attribute("isSolid")) == "true") {
        attr->solid = true;
    } else {
        attr->solid = false;
    }

    attr->harmful = true;

    attr->lifeTime = atof(element->Attribute("lifeTime"));
    attr->actLifeTime = 0.0;

    attr->width = atoi(element->Attribute("width"));
    attr->heigth = atoi(element->Attribute("heigth"));

    attr->pos.x = atoi(element->Attribute("posX"));
    attr->pos.y = atoi(element->Attribute("posY"));

    attr->origin.x =  atoi(element->Attribute("origX"));
    attr->origin.y  = atoi(element->Attribute("origY"));

    std::string textureName = element->Attribute("texture");


    attr->texture.loadFromFile(textureName);
    attr->sprite.setTexture(attr->texture);
    attr->sprite.setPosition(attr->pos.x, attr->pos.y );
    attr->sprite.setOrigin(attr->origin.x, attr->origin.y);

    return 0;
}

Fire::Initializer::Initializer(xmlElem_t& element, Fire::Attributes& attr)
{
    this->element = &element;   
    this->attr  = &attr;
}

Fire::Initializer::Initializer()
{
    this->element = NULL;
    this->attr =  NULL;
}

Fire::Initializer::~Initializer()
{
}
