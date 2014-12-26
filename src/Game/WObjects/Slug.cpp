#include "Game/WObjects/Slug.hpp"

Slug::Slug()
{
}

Slug::Slug(xmlElem_t& xmlElem, Vec2<float> pos)
{
    load(xmlElem);

    attr.pos  = pos;
    collisions = new CollisionManager;
    xmlElem_t* animationList = xmlElem.FirstChildElement("animations");
    anim.setSprite(attr.sprite);


    anim.loadAnimations(*animationList);
}

void Slug::setWorldObjects(WObjects& wObjects_)
{
    this->wObjects = &wObjects_;
    collisions->setWObjects((*this->wObjects));
    collisions->setTrackedObj(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
}


void Slug::handleEvents(const event_t& event)
{
}

void Slug::handleRealtimeEvents()
{
}

void Slug::chooseTarget()
{
    WObjects::iterator object = 
        std::find_if(std::begin(*wObjects), std::end(*wObjects), [](IWObjectPtr ob) -> bool { return ob->getAttr().groupID == 1;});
    if(object != wObjects->end()) attr.target = *object;
}

void Slug::update(const float& dt)
{
    attr.v.setComponents(0.0, 0.0);
    if(! attr.target) {
        chooseTarget();
    } else {
        move();
        // normalize speed components if diagonal movement
        if(attr.v.x != 0.f && attr.v.y != 0.f) {    
            attr.v.x /= std::sqrt(2.0);
            attr.v.y /= std::sqrt(2.0);
        }
    }

    updateCollisionExcludes();
    handleCollisions();
    updateCoordinates(dt);

    updateAnimation(dt);
}

void Slug::move()
{
    Vec2<float> targetPos = attr.target->getAttr().pos;
    targetPos.x > attr.pos.x ? attr.v.x = attr.vMax : attr.v.x = -attr.vMax ;
    targetPos.y > attr.pos.y ? attr.v.y = attr.vMax : attr.v.y = -attr.vMax ;
}

void Slug::updateAnimation(const float& dt)
{    
    anim.updateCurrentAnimation(dt);
}

void Slug::draw() 
{
    window->draw(attr.sprite);
}

void Slug::updateCoordinates(const float& dt)
{
    attr.pos.x += attr.v.x * dt;
    if(hasSolidCollisions()) attr.pos.x -= attr.v.x * dt;
    attr.pos.y += attr.v.y * dt;
    if(hasSolidCollisions()) attr.pos.y -= attr.v.y * dt;

    attr.sprite.setPosition(attr.pos.x, attr.pos.y);
}

void Slug::handleCollisions()
{
    CollisionManager::iterator last = collisions->end();
    for (CollisionManager::iterator it = collisions->begin(); it != last; ++it)
    {
        if((*it)->getAttr().groupID == attr.groupID) continue;
        if((*it)->getAttr().isHarmful() || (*it)->getAttr().groupID == 1) {
            destroyWObject(IWObjectPtr(this, [](IWorldsObject*){}));
            (*it)->addCollision(attr);
            IWObjectPtr blow = std::make_shared<Blow>(attr.pos, attr.groupID, Blow::STYLE::SLUG_BLOW);
            pushDeferred( [blow, this](DrawableScene * scene) {
                scene->add(blow, 0);
            });
        }
    }
}

bool Slug::hasSolidCollisions()
{
    CollisionManager::iterator last = collisions->end();
    for (CollisionManager::iterator it = collisions->begin(); it != last; ++it)
    {
        if(! isExclude(*it) && (*it)->getAttr().isSolid()) {
            return true;
        }
    }
    return false;
}

bool Slug::isExclude(IWObjectPtr verifiable)
{
    if( std::find(collisionExcludes.begin(), collisionExcludes.end(), verifiable) 
        != collisionExcludes.end() ) {
        return true;
    }
    return false;
}

void Slug::updateCollisionExcludes()
{
    collisionExcludes_t::iterator last = collisionExcludes.end();
    collisionExcludes_t::iterator it = collisionExcludes.begin();
    while( it != collisionExcludes.end()) {
        if(isNoLongerExisted(it) || ! alg::isCrossing(this->getAttr(), (*it)->getAttr()) ) {
            it = collisionExcludes.erase(it);
        } else {
            it++;
        }
    }
}

bool Slug::isNoLongerExisted(const collisionExcludes_t::iterator& item) {
    return (*item).use_count() < 2;
}

void Slug::load(xmlElem_t& elem)
{
    attr.groupID = atoi(elem.Attribute("groupID"));

    attr.solid = false;
    attr.harmful = true;
    
    attr.v.x = 0.0;
    attr.v.y = 0.0;
    attr.angle.setPiRadAngle(-0.5);
    attr.vMax = alg::parseInt(elem.Attribute("vMax"));;
    
    attr.width = alg::parseInt(elem.Attribute("width"));
    attr.heigth = alg::parseInt(elem.Attribute("heigth"));

    attr.origin.x =  alg::parseInt(elem.Attribute("origX"));
    attr.origin.y  = alg::parseInt(elem.Attribute("origY"));

    attr.texture.loadFromFile(elem.Attribute("texture"));
    attr.sprite.setTexture(attr.texture);
    
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
    attr.sprite.setOrigin(attr.origin.x, attr.origin.y);
}

Slug::Attributes::~Attributes()
{
}

Slug::~Slug()
{
    delete collisions;
}

IWorldsObject::Attributes&  Slug::getAttr() 
{
    return attr;
}