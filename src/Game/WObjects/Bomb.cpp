#include "Game/WObjects/Bomb.hpp"

Bomb::Bomb()
{
}

void Bomb::setWorldObjects(wObjects_t& wObjects)
{
    
    cManager.setWObjects(wObjects);
    cManager.setTrackedObj(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
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

Bomb::Bomb(const Vec2<float> pos, int groupId, float lifeTime)
{    

    attr.pos.x = pos.x;
    attr.pos.y = pos.y;
    attr.groupID = groupId;
    attr.lifeTime = lifeTime;

    TiXmlDocument * xmlFile = alg::openXmlFile("./res/DefaultWObjAttr.xml");
    xmlElem_t * xmlAttr = alg::getXmlElem(xmlFile, {"WObjects", "bomb"});

    load(*xmlAttr);
}

void Bomb::load(xmlElem_t& elem)
{
    attr.solid = false;
    attr.harmful = false;

    attr.actLifeTime = 0.0;

    attr.width = alg::parseInt(elem.Attribute("width"));
    attr.heigth = alg::parseInt(elem.Attribute("heigth"));
    attr.origin.x =  alg::parseInt(elem.Attribute("origX"));
    attr.origin.y  = alg::parseInt(elem.Attribute("origY"));

    attr.texture.loadFromFile(elem.Attribute("texture"));
    attr.sprite.setTexture(attr.texture);
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
    attr.sprite.setOrigin(attr.origin.x, attr.origin.y);
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


void Bomb::makeFire()
{
    //pWObject_t newFire = std::make_shared<Fire>(this->attr);
    pWObject_t newFire = std::make_shared<Fire>(attr.pos, attr.groupID, Fire::STYLE::BLOW);
    createSignal(newFire);

    for(Angle angle = 0; angle != Angle(2.f); angle += Angle(0.5)) {
        makeFireWave(angle);
    }
}

void Bomb::makeFireWave(Angle& angle)
{
    float offset = 32;
    int waveCount = 3;

    for(int i = 1; i < waveCount + 1; i++) {

        pWObject_t newFire = std::make_shared<Fire>(attr.pos + Vec2<float>(offset * i, angle), attr.groupID, Fire::STYLE::FLAME);
        createSignal(newFire);
        //cManager.setTrackedObj(std::shared_ptr<IWorldsObject>(newFire.get(), [](IWorldsObject*){}));
        cManager.setTrackedObj(newFire);
        for(CollisionManager::iterator it = cManager.begin(); it != cManager.end(); ++it) {
            if(it->getAttr().groupID == 0) it->addCollision(newFire->getAttr());
            if(it->getAttr().isSolid()) return ;
        }
    }
}


