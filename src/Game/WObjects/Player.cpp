#include "Game/WObjects/Player.hpp"

Player::Player()
{
}

Player::Player(xmlElem_t& xmlElem) : lastDirection("Down")
{
    load(xmlElem);

    collisManager = new CollisionManager;
    xmlElem_t* animationList = xmlElem.FirstChildElement("animations");
    anim.setSprite(attr.sprite);
    anim.loadAnimations(*animationList);

    attr.keys = new Keyset(Keyset::WSDASpace);
    actBinds[ACTIONS::MOVE_UP]    = std::bind(&Player::move, this, 0.0, -attr.vMax);
    actBinds[ACTIONS::MOVE_DOWN]  = std::bind(&Player::move, this, 0.0, attr.vMax) ;
    actBinds[ACTIONS::MOVE_RIGHT] = std::bind(&Player::move, this, attr.vMax, 0.0);
    actBinds[ACTIONS::MOVE_LEFT]  = std::bind(&Player::move, this, -attr.vMax, 0.0);
    actBinds[ACTIONS::THROW_BOMB] = std::bind(&Player::throwBomb, this);

    keyBinds[attr.keys->up ]   = ACTIONS::MOVE_UP ;
    keyBinds[attr.keys->down]  = ACTIONS::MOVE_DOWN ;
    keyBinds[attr.keys->right] = ACTIONS::MOVE_RIGHT ;
    keyBinds[attr.keys->left]  = ACTIONS::MOVE_LEFT ;
    keyBinds[attr.keys->space] = ACTIONS::THROW_BOMB ;
}

void Player::move(float vx, float vy)
{
    attr.v.x += vx;
    attr.v.y += vy;    
}

void Player::throwBomb()
{   
    float lifetime = 1.0;
    int layerIndex = 0;
    IWObjectPtr newBomb(new Bomb(attr.pos, attr.groupID, lifetime));

    collisionExcludes.push_back(newBomb); 
    pushDeferred([newBomb, layerIndex, this](DrawableScene * scene) {
        scene->add(newBomb, layerIndex);
    });
}

void Player::setWorldObjects(WObjects& wObjects_)
{
    this->wObjects = &wObjects_;
    collisManager->setWObjects((*this->wObjects));
    collisManager->setTrackedObj(std::shared_ptr<IWorldsObject>(this, [](IWorldsObject*){}));
}

Player::~Player()
{
    delete collisManager;
}
void Player::handleEvents(const event_t& event)
{
    if(event.type == sf::Event::KeyReleased) {
        if(event.key.code == attr.keys->space) {
            actions.push(actBinds[keyBinds[attr.keys->space]]);
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
    // normalize speed components if diagonal movement
    if(attr.v.x != 0.f && attr.v.y != 0.f) {    
        attr.v.x /= std::sqrt(2.0);
        attr.v.y /= std::sqrt(2.0);
    }

    updateImmunityState(dt);
    updateCollisionExcludes();
    updateCollisions();
    updateCoordinates(dt);

    updateAnimation(dt);
}

void Player::updateImmunityState(const float& dt)
{
    if(attr.immunity) {
        if(attr.immunity.timer >= attr.immunity.maxTime ) {
            attr.immunity.isActive = false;
            attr.immunity.timer = 0.f;
            attr.sprite.setColor(attr.oldColor);

        } else {
            attr.immunity.timer += dt;
        }
            
    }
     
}

void Player::updateAnimation(const float& dt)
{
    if(attr.v.getAbs() == 0.0f) {
        anim.setCurrent("stand" + lastDirection);
    } else {
        if(attr.v.y == 0) attr.v.x >  0.0 ? lastDirection = "Right" : lastDirection = "Left";
        else              attr.v.y >= 0.0 ? lastDirection = "Down"  : lastDirection = "Up";

        anim.setCurrent("move" + lastDirection);
    }
    
    anim.updateCurrentAnimation(dt);
}

void Player::draw() 
{
    window->draw(attr.sprite);
    window->draw(attr.healthIndicator);
}

void Player::updateCoordinates(const float& dt)
{
    attr.pos.x += attr.v.x * dt;
    if(hasSolidCollisions()) attr.pos.x -= attr.v.x * dt;
    attr.pos.y += attr.v.y * dt;
    if(hasSolidCollisions()) attr.pos.y -= attr.v.y * dt;

    attr.sprite.setPosition(attr.pos.x, attr.pos.y);
}

void Player::updateCollisions()
{
    using namespace std;
    for_each(begin(*collisManager), end(*collisManager), [this](IWObjectPtr & obj) {
        handleCollision(obj->getAttr());
    });

    while(! foreignCollisions.empty()) {
        handleCollision(foreignCollisions.top());
        foreignCollisions.pop();
    }
}

void Player::handleCollision(Collision & collision)
{
    if(collision.isHarmful()) {
        if( attr.healthIndicator.getString().getSize() == 1) {
            destroyWObject(IWObjectPtr(this,[](IWorldsObject*){}));
        } else if(! attr.immunity) {
            sf::String str = attr.healthIndicator.getString();
            str.erase(str.getSize() - 1);
            attr.healthIndicator.setString(str);
            attr.sprite.setColor(sf::Color::Red);
            attr.immunity.isActive = true;
        }

    }
}

void Player::addCollision(Collision collision)
{
    foreignCollisions.push(collision);
}

bool Player::hasSolidCollisions()
{
    
    CollisionManager::iterator last = collisManager->end();
    for (CollisionManager::iterator it = collisManager->begin(); it != last; ++it)
    {
        if(! isExclude(*it) && (*it)->getAttr().isSolid()) {
            return true;
        }
    }
    return false;
}

bool Player::isExclude(IWObjectPtr verifiable)
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
    collisionExcludes_t::iterator it = collisionExcludes.begin();
    while( it != collisionExcludes.end()) {
        if(isNoLongerExisted(it) || ! alg::isCrossing(this->getAttr(), (*it)->getAttr()) ) {
            it = collisionExcludes.erase(it);
        } else {
            it++;
        }
    }
}

bool Player::isNoLongerExisted(const collisionExcludes_t::iterator& item) {
    return (*item).use_count() < 2;
}

void Player::load(xmlElem_t& elem)
{
    attr.solid = false;
    attr.groupID = atoi(elem.Attribute("groupID"));

    attr.harmful = false;
    
    attr.v.x = 0.0;
    attr.v.y = 0.0;
    attr.angle.setPiRadAngle(-0.5);
    attr.vMax = 200;
    
    attr.width = alg::parseInt(elem.Attribute("width"));
    attr.heigth = alg::parseInt(elem.Attribute("heigth"));

    attr.origin.x =  alg::parseInt(elem.Attribute("origX"));
    attr.origin.y  = alg::parseInt(elem.Attribute("origY"));

    std::string textureName = elem.Attribute("texture");

    attr.texture.loadFromFile(textureName);
    attr.sprite.setTexture(attr.texture);
    
    attr.immunity.maxTime = alg::parseFloat(elem.Attribute("maxImmunityTime"));
    attr.immunity.timer = 0.f;
    attr.immunity.isActive = false;


    xmlElem_t * indAttr = elem.FirstChildElement("healthIndicator");
    std::string indicator;
    int health = alg::parseInt(indAttr->Attribute("health"));
    for(int i = 0; i < health; i++) 
        indicator.push_back('@');
    attr.healthIndicator.setString(indicator);

    attr.font.loadFromFile(indAttr->Attribute("font"));
    attr.healthIndicator.setFont(attr.font);
    attr.healthIndicator.setColor(sf::Color::Red);
    attr.healthIndicator.setPosition( alg::parseInt(indAttr->Attribute("posX")), alg::parseInt(indAttr->Attribute("posY")) );


    attr.pos.x = alg::parseInt(elem.Attribute("posX"));
    attr.pos.y = alg::parseInt(elem.Attribute("posY"));
    attr.sprite.setPosition(attr.pos.x, attr.pos.y );
    attr.sprite.setOrigin(attr.origin.x, attr.origin.y);

    attr.oldColor = attr.sprite.getColor();
}

Player::Attributes::~Attributes()
{
    if(keys != nullptr) delete keys;
}

IWorldsObject::Attributes&  Player::getAttr() 
{
    return attr;
}