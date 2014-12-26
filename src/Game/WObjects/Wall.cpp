#include "Game/WObjects/Wall.hpp"

Wall::Wall()
{
}

Wall::Wall(xmlElem_t& elem)
{    
    load(elem);
}

void Wall::setWorldObjects(WObjects& wObjects)
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
        destroyWObject(IWObjectPtr(this, [](IWorldsObject*){}));
    }
}

void Wall::load(xmlElem_t& elem)
{
    std::string(elem.Attribute("isSolid")) == "true" ? attr.solid = true : attr.solid = false;
    std::string(elem.Attribute("invulnerable")) == "true" ? attr.invulnerable = true : attr.invulnerable = false;

    attr.harmful = false;
    attr.groupID = atoi(elem.Attribute("groupID"));

    attr.width = atoi(elem.Attribute("width"));
    attr.heigth = atoi(elem.Attribute("heigth"));

    attr.pos.x = atoi(elem.Attribute("posX"));
    attr.pos.y = atoi(elem.Attribute("posY"));

    attr.origin.x =  atoi(elem.Attribute("origX"));
    attr.origin.y  = atoi(elem.Attribute("origY"));

    attr.texture.loadFromFile(elem.Attribute("texture"));
    attr.sprite.setTexture(attr.texture);
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
    attr.sprite.setOrigin(attr.origin.x, attr.origin.y);
}
