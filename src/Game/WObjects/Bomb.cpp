#include "Game/WObjects/Bomb.hpp"

Bomb::Bomb()
{
}

void Bomb::setWorldObjects(WObjects& wObjects)
{
    
    collisManager.setWObjects(wObjects);
    collisManager.setTrackedObj(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
    this->wObjects = &wObjects;
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
    delete xmlFile;
}

void Bomb::load(xmlElem_t& elem)
{
    attr.solid = true;
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
        destroyWObject(IWObjectPtr(this, [](IWorldsObject*){}));
    }
}

void Bomb::destroyWObject(IWObjectPtr object)
{
    pushDeferred([object, this](DrawableScene * scene) {
        scene->remove(object);
    });
}

void Bomb::createWObject(IWObjectPtr object)
{
    pushDeferred([object, this](DrawableScene * scene) {
        scene->add(object, 0);
    });
}

void Bomb::draw()
{
    window->draw(attr.sprite);
}


void Bomb::makeFire()
{
    for(Angle angle = 0; angle != Angle(2.f); angle += Angle(0.5)) {
        makeFireWave(angle);
    }
    createWObject(std::make_shared<Blow>(attr.pos, attr.groupID, Blow::STYLE::BLOW));
}

void Bomb::makeFireWave(Angle& angle)
{
    float offset = 32;
    int waveCount = 3;

    for(int i = 1; i < waveCount + 1; i++) {
        IWObjectPtr newFire = std::make_shared<Blow>(attr.pos + Vec2<float>(offset * i, angle), attr.groupID, Blow::STYLE::FLAME);
        createWObject(newFire);

        collisManager.setTrackedObj(newFire);
        for(CollisionManager::iterator it = collisManager.begin(); it != collisManager.end(); ++it) {
            if(it->getAttr().groupID == 0) it->addCollision(newFire->getAttr());
            if(it->getAttr().isSolid()) return ;
        }
    }
}


IWorldsObject::Attributes& Bomb::getAttr() 
{
    return attr;
}
