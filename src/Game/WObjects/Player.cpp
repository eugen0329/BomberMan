#include "Game/WObjects/Player.hpp"

Player::Player()
{
}

Player::Player(xmlElem_t& xmlElem) : lastDirection("Down")
{
    load(xmlElem);

    collisions = new CollisionManager;
    xmlElem_t* animationList = xmlElem.FirstChildElement("animations");
    anim.setSprite(attr.sprite);
    anim.loadAnimations(*animationList);

    move = [&](float vx, float vy) {
        attr.v.x += vx;
        attr.v.y += vy;      
    };

    throwBomb = [&]() {
        pWObject_t newBomb(new Bomb(attr));
        createWObject(newBomb);
        collisionExcludes.push_back(newBomb);   
    };

    keys = new Keyset(Keyset::WSDASpace);
    actBinds[ACTIONS::MOVE_UP]    = std::bind(move, 0.0, -attr.vMax);
    actBinds[ACTIONS::MOVE_DOWN]  = std::bind(move, 0.0, attr.vMax) ;
    actBinds[ACTIONS::MOVE_RIGHT] = std::bind(move, attr.vMax, 0.0);
    actBinds[ACTIONS::MOVE_LEFT]  = std::bind(move, -attr.vMax, 0.0);
    actBinds[ACTIONS::THROW_BOMB] = std::bind(throwBomb);

    keyBinds[keys->up ]   = ACTIONS::MOVE_UP ;
    keyBinds[keys->down]  = ACTIONS::MOVE_DOWN ;
    keyBinds[keys->right] = ACTIONS::MOVE_RIGHT ;
    keyBinds[keys->left]  = ACTIONS::MOVE_LEFT ;
    keyBinds[keys->space] = ACTIONS::THROW_BOMB ;

}

void Player::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    } else if(signalName == "create") {
        createWObject = *delegate;
    }
}

void Player::setWorldObjects(wObjects_t& wObjects_)
{
    this->wObjects = &wObjects_;
    collisions->setWObjects((*this->wObjects));
    collisions->setOwner(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
}

Player::~Player()
{
    delete collisions;
}
void Player::handleEvents(const event_t& event)
{
    if(event.type == sf::Event::KeyReleased) {
        if(event.key.code == keys->space) {
            actions.push(actBinds[keyBinds[keys->space]]);
        }
    }
}

void Player::handleRealtimeEvents()
{
    using namespace std;
    for_each(begin(keyBinds), end(keyBinds), [&](pair<sf::Keyboard::Key, ACTIONS> it) {
        if(sf::Keyboard::isKeyPressed(it.first) && keyBinds[it.first] != ACTIONS::THROW_BOMB) {
            actions.push(actBinds[keyBinds[it.first]]);
        }
    });
}

void Player::update(const float& dt)
{
    handleRealtimeEvents();
    attr.v.setComponents(0.0, 0.0);
    while(! actions.empty()) {
        action_t action = actions.top();
        action(dt);
        actions.pop();
    }

    if(attr.v.x != 0.f && attr.v.y != 0.f) {
        attr.v.x /= std::sqrt(2.0);
        attr.v.y /= std::sqrt(2.0);
    }

    changeAnimation();
    
    anim.updateCurrentAnimation(dt);
    updateCollisionExcludes();
    updateCoordinates(dt);
    handleCollisions();

}

void Player::changeAnimation()
{
    if(attr.v.getAbs() == 0.0f) {
        anim.setCurrent("stand" + lastDirection);
        return ;
    }

    if(attr.v.y == 0) {
        attr.v.x > 0.0 ? lastDirection = "Right" : lastDirection = "Left";
    } else {
        attr.v.y >= 0.0 ? lastDirection = "Down" : lastDirection = "Up";
    }
    anim.setCurrent("move" + lastDirection);
}

void Player::draw() 
{
    window->draw(attr.sprite);
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
            attr.sprite.setColor(sf::Color::Red);
        }
    }
}


bool Player::hasSolidCollisions()
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

bool Player::isExclude(pWObject_t verifiable)
{
    if( std::find(collisionExcludes.begin(), collisionExcludes.end(), verifiable) 
        != collisionExcludes.end() ) {
        return true;
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
