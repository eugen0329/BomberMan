#include "Game/WObjects/Bomb.hpp"

Bomb::Bomb()
{
}

//Bomb::Bomb(xmlElement_t& xmlElement, int groupID)
//{    
//	Bomb::Initializer initializer(xmlElement, attrib);
//
//    if(initializer.load()) {
//        exit(1);
//    }    
//    attrib.groupID = groupID;
//    //setObjectID("Bomb");
//}

void Bomb::setWorldsObjectsVector(wObjects_t& wObjects)
{
    this->wObjects = &wObjects;
}

Bomb::Bomb(xmlElement_t& xmlElement, const IAttributes& parAttr)
{    
	Bomb::Initializer initializer(xmlElement, attrib);

    if(initializer.load()) {
        exit(1);
    }    

    attrib.pos.x = parAttr.pos.x;
    attrib.pos.y = parAttr.pos.y;
    attrib.sprite.setPosition(attrib.pos.x, attrib.pos.y );
}

Bomb::Bomb(const IAttributes& parAttr)
{    

    attrib.solid = false;

    attrib.groupID = parAttr.groupID;

    attrib.lifeTime = 3;
    attrib.actLifeTime = 0.0;

    attrib.width = 32;
    attrib.heigth = 32;

    attrib.origin.x =  16;
    attrib.origin.y  = 16;

    std::string textureName = "res/Tiles/bomb.jpg";

    attrib.texture.loadFromFile(textureName);
    attrib.sprite.setTexture(attrib.texture);
    attrib.sprite.setOrigin(attrib.origin.x, attrib.origin.y);
    attrib.pos.x = parAttr.pos.x;
    attrib.pos.y = parAttr.pos.y;
    attrib.sprite.setPosition(attrib.pos.x, attrib.pos.y );
}

void Bomb::addCollision(Collision)
{
}

Bomb::~Bomb()
{
}

void Bomb::handleEvents(const event_t&)
{
} 

void Bomb::update(const float& dt) 
{ 
    attrib.actLifeTime += dt;
 
    //std::cout <<  attrib.actLifeTime;
    if(attrib.actLifeTime >= attrib.lifeTime) 
    {
        destroyingSignal(dynamic_cast<IWorldsObject*>(this));
    }
}

void Bomb::handleCollisions()
{
}
void Bomb::checkCollisions()
{
}

void Bomb::draw()
{
    window->draw(attrib.sprite);
}

void Bomb::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    }
}

int Bomb::Initializer::load() const
{
    if(attrib == NULL) {
        return 1; 
    }


    if(std::string(element->Attribute("isSolid")) == "true") {
        attrib->solid = true;
    } else {
        attrib->solid = false;
    }

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

Bomb::Initializer::Initializer(xmlElement_t& element, BombAttributes& attrib)
{
    this->element = &element;   
    this->attrib  = &attrib;
}

Bomb::Initializer::Initializer()
{
    this->element = NULL;
    this->attrib =  NULL;
}

Bomb::Initializer::~Initializer()
{
}
