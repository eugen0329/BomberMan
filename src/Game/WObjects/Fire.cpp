#include "Game/WObjects/Fire.hpp"

Fire::Fire()
{
}

void Fire::setWorldsObjectsVector(wObjects_t& wObjects)
{
    this->wObjects = &wObjects;
}

Fire::Fire(const IAttributes& parAttr, Vector2D<float> offset)
{    
    attrib.harmful = true; 
    attrib.solid = false;

    attrib.groupID = parAttr.groupID;

    attrib.damage = 20;
    attrib.lifeTime = 1;
    attrib.actLifeTime = 0.0;

    attrib.width = 32;
    attrib.heigth = 32;

    attrib.origin.x =  16;
    attrib.origin.y  = 16;

    std::string textureName = "res/Tiles/fire.png";

    attrib.texture.loadFromFile(textureName);
    attrib.sprite.setTexture(attrib.texture);
    attrib.sprite.setOrigin(attrib.origin.x, attrib.origin.y);
    attrib.pos.x = parAttr.pos.x;
    attrib.pos.y = parAttr.pos.y;

    attrib.pos += offset;

    attrib.sprite.setPosition(attrib.pos.x, attrib.pos.y );
}

Fire::Fire(xmlElement_t& xmlElement)
{    
	Fire::Initializer initializer(xmlElement, attrib);

    if(initializer.load()) {
        exit(1);
    }    

}

Fire::Fire(const IAttributes& parAttr)
{    
    attrib.harmful = true; 
    attrib.solid = false;

    attrib.groupID = parAttr.groupID;

    attrib.damage = 20;
    attrib.lifeTime = 1;
    attrib.actLifeTime = 0.0;

    attrib.width = 32;
    attrib.heigth = 32;

    attrib.origin.x =  16;
    attrib.origin.y  = 16;

    std::string textureName = "res/Tiles/fire.png";

    attrib.texture.loadFromFile(textureName);
    attrib.sprite.setTexture(attrib.texture);
    attrib.sprite.setOrigin(attrib.origin.x, attrib.origin.y);
    attrib.pos.x = parAttr.pos.x;
    attrib.pos.y = parAttr.pos.y;
    attrib.sprite.setPosition(attrib.pos.x, attrib.pos.y );
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
    attrib.actLifeTime += dt;
 
    //std::cout <<  attrib.actLifeTime;
    if(attrib.actLifeTime >= attrib.lifeTime) 
    {
        destroyingSignal(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
    }
}

void Fire::handleCollisions()
{
}
void Fire::checkCollisions()
{
}

void Fire::draw()
{
    window->draw(attrib.sprite);
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
    if(attrib == NULL) {
        return 1; 
    }


    if(std::string(element->Attribute("isSolid")) == "true") {
        attrib->solid = true;
    } else {
        attrib->solid = false;
    }

    attrib->harmful = true;

    attrib->lifeTime = atof(element->Attribute("lifeTime"));
    attrib->actLifeTime = 0.0;

    attrib->width = atoi(element->Attribute("width"));
    attrib->heigth = atoi(element->Attribute("heigth"));

    attrib->pos.x = atoi(element->Attribute("posX"));
    attrib->pos.y = atoi(element->Attribute("posY"));

    attrib->origin.x =  atoi(element->Attribute("origX"));
    attrib->origin.y  = atoi(element->Attribute("origY"));

    std::string textureName = element->Attribute("texture");


    attrib->texture.loadFromFile(textureName);
    attrib->sprite.setTexture(attrib->texture);
    attrib->sprite.setPosition(attrib->pos.x, attrib->pos.y );
    attrib->sprite.setOrigin(attrib->origin.x, attrib->origin.y);

    return 0;
}

Fire::Initializer::Initializer(xmlElement_t& element, FireAttributes& attrib)
{
    this->element = &element;   
    this->attrib  = &attrib;
}

Fire::Initializer::Initializer()
{
    this->element = NULL;
    this->attrib =  NULL;
}

Fire::Initializer::~Initializer()
{
}
