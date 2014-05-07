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
    
    cManager.setWObjects(wObjects);
    cManager.setOwner(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
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

    attrib.solid = true;
    attrib.harmful = false;

    attrib.groupID = parAttr.groupID;

    attrib.lifeTime = 1;
    attrib.actLifeTime = 0.0;

    attrib.width = 32;
    attrib.heigth = 32;

    attrib.origin.x =  16;
    attrib.origin.y  = 16;


    std::string textureName = "res/Tiles/bomb1.png";

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
    window->draw(attrib.sprite);
}

void Bomb::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    } else if(signalName == "create") {
        this->createSignal = *delegate;        
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


    attrib->harmful = false;

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

void Bomb::makeFire()
{



    pWObject_t newFire = std::make_shared<Fire>(this->attrib);
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
        pWObject_t newFire = std::make_shared<Fire>(this->attrib, Vector2D<float>(offset * wave, angle));
        createSignal(newFire);
        cManager.setOwner(std::shared_ptr<IWorldsObject>(newFire.get(), [](IWorldsObject*){}));
        for(CollisionManager::iterator it = cManager.begin(); it != cManager.end(); ++it) {
            // 0 - is static objects that cant react on external collisions by themself
            if(it->getAttributes().groupID != 0) continue;
            it->addCollision(newFire->getAttributes());
            if(it->getAttributes().isSolid()) return ;
        }
    }
}


