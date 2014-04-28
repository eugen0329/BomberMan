#include "Game/WObjects/Wall.hpp"

Wall::Wall()
{
}

Wall::Wall(xmlElement_t& xmlElement)
{    
	Wall::Initializer initializer(xmlElement, attrib);

    if(initializer.load()) {
        exit(1);
    } 
    //setObjectID("Wall");
}

void Wall::setWorldsObjectsVector(wObjects_t& wObjects)
{
    this->wObjects = &wObjects;
}

void Wall::handleEvents(const event_t&)
{
}

void Wall::update(const float&)
{
}

void Wall::draw()
{
    window->draw(attrib.sprite);
}

void Wall::handleCollisions()
{
}
void Wall::checkCollisions()
{
}

int Wall::Initializer::load() const
{
    if(attrib == NULL) {
        return 1;
    }

    if(std::string(element->Attribute("isSolid")) == "true") {
        attrib->solid = true;
    } else {
        attrib->solid = false;
    }
    attrib->groupID = atoi(element->Attribute("groupID"));

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

Wall::Initializer::Initializer(xmlElement_t& element, WallAttributes& attrib)
{
    this->element = &element;   
    this->attrib  = &attrib;
}

Wall::Initializer::Initializer()
{
    this->element = NULL;
    this->attrib =  NULL;
}

Wall::Initializer::~Initializer()
{
}
