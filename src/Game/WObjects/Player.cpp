#include "Game/WObjects/Player.hpp"

Player::Player()
{
}

Player::Player(xmlElem_t& xmlElement)
{
    Player::Initializer initializer(xmlElement, attr);

    if(initializer.load()) {
        exit(1);
    } 

    collisions = new CollisionManager;
    xmlElem_t* animationList = xmlElement.FirstChildElement("animations");
    if(animationList == NULL) {
        exit(1);
    }
    animationManager.setSprite(attr.sprite);
    animationManager.loadAnimations(*animationList);



    Delegate delegate;

    act.setPlayerAttr(attr);
    act.setAnimationManager(animationManager);
    act.setSignal(&delegate.bind(this, & Player::addCollisionExclude), "addCollisionExclude");

    // retrieving keyset according groupId
    Keyset keyset(static_cast<Keyset::SetID>(attr.groupID));
    eventManager = new PlayerEventManager(keyset);
    eventManager->setAction(&delegate.bind(&act, & Actions::stop), "stop"); 
    eventManager->setAction(&delegate.bind(&act, & Actions::move), "move"); 
    eventManager->setAction(&delegate.bind(&act, & Actions::throwBomb), "throwBomb"); 
}

void Player::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    } else if(signalName == "create") {
         act.setSignal(delegate, signalName);
    }
}

void Player::setWorldObjects(wObjects_t& wObjects_)
{
    this->wObjects = &wObjects_;
    act.setWObjects(wObjects_);
    collisions->setWObjects((*this->wObjects));
    collisions->setOwner(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
}

Player::~Player()
{
    delete collisions;
    delete eventManager;
}

void Player::handleEvents(const event_t& event)
{
    eventManager->handleEvents(event);
}

void Player::update(const float& dt)
{
    animationManager.updateCurrentAnimation(dt);
    updateCoordinates(dt);
}

void Player::draw() 
{
    window->draw(attr.sprite);
}

void Player::addCollisionExclude(pWObject_t newExclude) 
{
    collisionExcludes.push_back(newExclude);
}

void Player::updateCoordinates(const float& dt)
{
    attr.pos.x += attr.v.x * dt;
    if(hasSolidCollisions()) attr.pos.x -= attr.v.x * dt;
    attr.pos.y += attr.v.y * dt;
    if(hasSolidCollisions()) attr.pos.y -= attr.v.y * dt;

    attr.sprite.setPosition(attr.pos.x, attr.pos.y);
}

void Player::handleCollisions()
{
    CollisionManager::iterator last = collisions->end();
    for (CollisionManager::iterator it = collisions->begin(); it != last; ++it)
    {
        if((*it)->getAttr().isHarmful()) {
            //destroyingSignal(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
            attr.sprite.setColor(sf::Color::Red);
        }
    }
}

bool Player::isExclude(pWObject_t verifiable)
{
    if( std::find(collisionExcludes.begin(), collisionExcludes.end(), verifiable) 
        != collisionExcludes.end() ) {
        return true;
    }
    return false;
}

void Player::addCollision(Collision)
{
}

bool Player::hasSolidCollisions()
{
    updateCollisionExcludes();
    CollisionManager::iterator last = collisions->end();
    for (CollisionManager::iterator it = collisions->begin(); it != last; ++it)
    {
        if(! isExclude(*it) && (*it)->getAttr().isSolid()) {
            return true;
        }
    }
    return false;
}

void Player::updateCollisionExcludes()
{
    collisionExcludes_t::iterator last = collisionExcludes.end();
    for(collisionExcludes_t::iterator it = collisionExcludes.begin(); it != last; it++) {
        // if the object no longer exists or if bomber do not crossing the object 
        if(  (*it).use_count() < 2 || ! alg::isCrossing(this->getAttr(), (*it)->getAttr())) {
            collisionExcludes.erase(it);
            it--;
        }

    }
}

// Initializer /---------------------------

Player::Initializer::Initializer(xmlElem_t& element, PlayerAttributes& attr)
{
    this->element = &element;   
    this->attr  = &attr;
}

Player::Initializer::Initializer()
{
    this->element = NULL;
    this->attr =  NULL;
}

Player::Initializer::~Initializer()
{
}

int Player::Initializer::load() const
{

    if(attr == NULL) {
        return 1;
    }

    if(std::string(element->Attribute("isSolid")) == "true") {
        attr->solid = true;
    } else {
        attr->solid = false;
    }

    attr->groupID = atoi(element->Attribute("groupID"));

    attr->harmful = false;
    

    attr->v.x = 0.0;
    attr->v.y = 0.0;
    attr->angle.setPiRadAngle(-0.5);
    attr->vMax = 200;
    
    attr->width = atoi(element->Attribute("width"));;
    attr->heigth = atoi(element->Attribute("heigth"));

    attr->origin.x =  atoi(element->Attribute("origX"));
    attr->origin.y  = atoi(element->Attribute("origY"));

    std::string textureName = element->Attribute("texture");

    attr->texture.loadFromFile(textureName);
    attr->sprite.setTexture(attr->texture);
    
    attr->pos.x = atoi(element->Attribute("posX"));
    attr->pos.y = atoi(element->Attribute("posY"));
    attr->sprite.setPosition(attr->pos.x, attr->pos.y );
    attr->sprite.setOrigin(attr->origin.x, attr->origin.y);
    return 0;
}
