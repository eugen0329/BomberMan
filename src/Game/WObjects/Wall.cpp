#include "Game/WObjects/Wall.hpp"

Wall::Wall()
{
}

Wall::Wall(xmlElem_t& xmlElement)
{    
	Wall::Initializer initializer(xmlElement, attr);

    if(initializer.load()) {
        exit(1);
    }
}

void Wall::setWorldObjects(wObjects_t& wObjects)
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
    window->draw(attr.sprite);
}

void Wall::addCollision(Collision collision) 
{
    if(collision.isHarmful()) {
        destroyingSignal(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
    }
}

int Wall::Initializer::load() const
{
    if(attr == NULL) {
        return 1;
    }

    if(std::string(element->Attribute("isSolid")) == "true") {
        attr->solid = true;
    } else {
        attr->solid = false;
    }
    attr->harmful = false;
    attr->groupID = atoi(element->Attribute("groupID"));

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

Wall::Initializer::Initializer(xmlElem_t& element, Wall::Attributes& attr)
{
    this->element = &element;   
    this->attr  = &attr;
}

Wall::Initializer::Initializer()
{
    this->element = NULL;
    this->attr =  NULL;
}

Wall::Initializer::~Initializer()
{
}

