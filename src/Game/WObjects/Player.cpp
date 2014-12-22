#include "Game/WObjects/Player.hpp"

Player::Player()
{
}

Player::Player(xmlElem_t& xmlElem)
{
    load(xmlElem);

    collisions = new CollisionManager;
    xmlElem_t* animationList = xmlElem.FirstChildElement("animations");
    animationManager.setSprite(attr.sprite);
    animationManager.loadAnimations(*animationList);

    act.addCollisionExclude = [&](pWObject_t n) { collisionExcludes.push_back(n);};
    act.setKeyset(new Keyset(Keyset::WSDASpace));
    act.load(attr, animationManager);
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
}

void Player::handleEvents(const event_t& event)
{
    act.handleEvents(event);
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

void Player::load(xmlElem_t& elem)
{
    if(std::string(elem.Attribute("isSolid")) == "true") {
        attr.solid = true;
    } else {
        attr.solid = false;
    }

    attr.groupID = atoi(elem.Attribute("groupID"));

    attr.harmful = false;
    

    attr.v.x = 0.0;
    attr.v.y = 0.0;
    attr.angle.setPiRadAngle(-0.5);
    attr.vMax = 200;
    
    attr.width = atoi(elem.Attribute("width"));;
    attr.heigth = atoi(elem.Attribute("heigth"));

    attr.origin.x =  atoi(elem.Attribute("origX"));
    attr.origin.y  = atoi(elem.Attribute("origY"));

    std::string textureName = elem.Attribute("texture");

    attr.texture.loadFromFile(textureName);
    attr.sprite.setTexture(attr.texture);
    
    attr.pos.x = atoi(elem.Attribute("posX"));
    attr.pos.y = atoi(elem.Attribute("posY"));
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
    attr.sprite.setOrigin(attr.origin.x, attr.origin.y);
}
