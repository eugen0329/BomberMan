#include "Game/WObjects/Player.hpp"

Player::Player()
{
}

Player::Player(xmlElement_t& xmlElement)
{
    Player::Initializer initializer(xmlElement, attrib);

    //setObjectID("Player");
    if(initializer.load()) {
        exit(1);
    } 

    initializeComponents(xmlElement);
}

void Player::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    } else if(signalName == "create") {
         act.setSignal(delegate, signalName);
    }
}

void Player::initializeComponents(xmlElement_t& element)
{
    collisions = new CollisionManager;
    xmlElement_t* animationList = element.FirstChildElement("animations");
    if(animationList == NULL) {
        exit(1);
    }
    animationManager.setSprite(attrib.sprite);
    animationManager.loadAnimations(*animationList);

    act.setPlayerAttributes(attrib);
    act.setAnimationManager(animationManager);
    act.setSignal(alg::createSignal(this, & Player::addCollisionExclude), "addCollisionExclude");

    eventManager.setAction(alg::createSignal(&act, & Actions::stop), "stop"); 
    eventManager.setAction(alg::createSignal(&act, & Actions::move), "move"); 
    eventManager.setAction(alg::createSignal(&act, & Actions::throwBomb), "throwBomb"); 
 
}

void Player::setWorldsObjectsVector(wObjects_t& wObjects_)
{
    this->wObjects = &wObjects_;
    act.setWObjects(wObjects_);
    collisions->setWObjects((*this->wObjects));
    collisions->setOwner(std::shared_ptr<IWorldsObject>(this));
}

Player::~Player()
{
}

void Player::handleEvents(const event_t& event)
{
    eventManager.handleEvents(event);
}

void Player::update(const float& dt)
{
    animationManager.updateCurrentAnimation(dt);
    updateCoordinates(dt);
}

void Player::draw() 
{
    window->draw(attrib.sprite);
}

void Player::addCollisionExclude(pWObject_t newExclude) 
{
    collisionExcludes.push_back(newExclude);
}

void Player::updateCoordinates(const float& dt)
{
    attrib.pos.x += attrib.v.x * dt;
    if(checkCollisions()) attrib.pos.x -= attrib.v.x * dt;

    attrib.pos.y += attrib.v.y * dt;
    if(checkCollisions()) attrib.pos.y -= attrib.v.y * dt;

    attrib.sprite.setPosition(attrib.pos.x, attrib.pos.y);
}

void Player::handleCollisions()
{
}

bool Player::isExclude(pWObject_t verifiable)
{
    if( std::find(collisionExcludes.begin(), collisionExcludes.end(), verifiable) 
        != collisionExcludes.end() ) {
        return true;
    }
    return false;
}

bool Player::checkCollisions()
{
    updateCollisionExcludes();

    bool hasCollisions = false;

    //pWObject_t it;
    //for(it = collisions->firstCollision(); it != 0; it = collisions->nextCollision()) {
    //    if(isExclude(it)) continue;
    //    it->addCollision(this->getAttributes());
//
    //    hasCollisions = true;
    //}
    CollisionManager::iterator last = collisions->end();
    for (CollisionManager::iterator it = collisions->begin(); it != last; ++it)
    {
        if(! isExclude(*it) && (*it)->getAttributes().isSolid()) {
            (*it)->addCollision(this->getAttributes());
            hasCollisions = true;
        }
    }
    return hasCollisions;
}

void Player::updateCollisionExcludes()
{
    collisionExcludes_t::iterator last = collisionExcludes.end();
    for(collisionExcludes_t::iterator it = collisionExcludes.begin(); it != last; it++) {
        // if the object no longer exists or if bomber do not crossing the object 
        if(  (*it).use_count() < 2 || ! alg::isCrossing(this->getAttributes(), (*it)->getAttributes())) {
            collisionExcludes.erase(it);
            it--;
        }

    }
}

// Initializer /---------------------------

Player::Initializer::Initializer(xmlElement_t& element, PlayerAttributes& attrib)
{
    this->element = &element;   
    this->attrib  = &attrib;
}

Player::Initializer::Initializer()
{
    this->element = NULL;
    this->attrib =  NULL;
}

Player::Initializer::~Initializer()
{
}

int Player::Initializer::load() const
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

    attrib->harmful = false;
    

    attrib->v.x = 0.0;
    attrib->v.y = 0.0;
    attrib->angle.setPiRadAngle(-0.5);
    attrib->vMax = 200;
    
    attrib->width = atoi(element->Attribute("width"));;
    attrib->heigth = atoi(element->Attribute("heigth"));

    attrib->origin.x =  atoi(element->Attribute("origX"));
    attrib->origin.y  = atoi(element->Attribute("origY"));

    std::string textureName = element->Attribute("texture");

    attrib->texture.loadFromFile(textureName);
    attrib->sprite.setTexture(attrib->texture);
    
    attrib->pos.x = atoi(element->Attribute("posX"));
    attrib->pos.y = atoi(element->Attribute("posY"));
    attrib->sprite.setPosition(attrib->pos.x, attrib->pos.y );
    attrib->sprite.setOrigin(attrib->origin.x, attrib->origin.y);
    //attrib->sprite.setTextureRect(sf::IntRect(0,128, attrib->width, attrib->heigth ) );
    return 0;
}
