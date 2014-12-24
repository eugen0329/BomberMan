#include "Game/WObjects/Bomb.hpp"

Bomb::Bomb()
{
}

void Bomb::setWorldObjects(wObjects_t& wObjects)
{
    
    cManager.setWObjects(wObjects);
    cManager.setOwner(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
    this->wObjects = &wObjects;
}

Bomb::Bomb(xmlElem_t& xmlElement, const IWorldsObject::Attributes& parAttr)
{    
	load(xmlElement);

    attr.pos.x = parAttr.pos.x;
    attr.pos.y = parAttr.pos.y;
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
}

Bomb::Bomb(const IWorldsObject::Attributes& parAttr)
{    

    attr.solid = true;
    attr.harmful = false;

    attr.groupID = parAttr.groupID;

    attr.lifeTime = 1;
    attr.actLifeTime = 0.0;

    attr.width = 32;
    attr.heigth = 32;

    attr.origin.x =  16;
    attr.origin.y  = 16;


    std::string textureName = "res/Tiles/bomb1.png";

    attr.texture.loadFromFile(textureName);
    attr.sprite.setTexture(attr.texture);
    attr.sprite.setOrigin(attr.origin.x, attr.origin.y);
    attr.pos.x = parAttr.pos.x;
    attr.pos.y = parAttr.pos.y;
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
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
    attr.actLifeTime += dt;
    if(attr.actLifeTime >= attr.lifeTime) 
    {
        makeFire();
        destroyingSignal(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
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
    window->draw(attr.sprite);
}

void Bomb::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    } else if(signalName == "create") {
        this->createSignal = *delegate;        
    }

}

void Bomb::load(xmlElem_t& elem)
{
    if(std::string(elem.Attribute("isSolid")) == "true") {
        attr.solid = true;
    } else {
        attr.solid = false;
    }

    attr.harmful = false;

    attr.lifeTime = atof(elem.Attribute("lifeTime"));
    attr.actLifeTime = 0.0;

    attr.width = atoi(elem.Attribute("width"));
    attr.heigth = atoi(elem.Attribute("heigth"));

    attr.pos.x = atoi(elem.Attribute("posX"));
    attr.pos.y = atoi(elem.Attribute("posY"));

    attr.origin.x =  atoi(elem.Attribute("origX"));
    attr.origin.y  = atoi(elem.Attribute("origY"));

    std::string textureName = elem.Attribute("texture");


    attr.texture.loadFromFile(textureName);
    attr.sprite.setTexture(attr.texture);
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
    attr.sprite.setOrigin(attr.origin.x, attr.origin.y);
}

void Bomb::makeFire()
{
    pWObject_t newFire = std::make_shared<Fire>(this->attr);
    createSignal(newFire);

    for(Angle angle = 0; angle != Angle(2.f); angle += Angle(0.5)) {
        makeFireWave(angle);
    }
}

void Bomb::makeFireWave(Angle& angle)
{
    float offset = 32;
    int waveCount = 3;

    for(int wave = 1; wave < waveCount + 1; wave++) {
        pWObject_t newFire = std::make_shared<Fire>(this->attr, Vec2<float>(offset * wave, angle));
        createSignal(newFire);
        cManager.setOwner(std::shared_ptr<IWorldsObject>(newFire.get(), [](IWorldsObject*){}));
        for(CollisionManager::iterator it = cManager.begin(); it != cManager.end(); ++it) {
            // 0 - is static objects that cant react on external collisions by themself
            if(it->getAttr().groupID != 0) continue;
            it->addCollision(newFire->getAttr());
            if(it->getAttr().isSolid()) return ;
        }
    }
}


