#include "Game/WObjects/Player.hpp"

Player::Player()
{
}

Player::Player(xmlElement_t& xmlElement)
{
    Player::Initializer initializer(xmlElement, attrib);

    if(initializer.load()) {
        exit(1);
    } 

    initializeAggregates(xmlElement);
}

void Player::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    } else if(signalName == "create") {
         act.setSignal(delegate, signalName);
    }
}

void Player::initializeAggregates(xmlElement_t& element)
{
    xmlElement_t* animationList = element.FirstChildElement("animations");
    if(animationList == NULL) {
        exit(1);
    }
    animationManager.setObjectAttributes(attrib);
    animationManager.loadAnimations(*animationList);

    act.setPlayerAttributes(attrib);
    act.setAnimationManager(animationManager);
    //act.setSignalsQueue(signals);

    Delegate action;

    eventManager.setAction(alg::createSignal(&act, & Actions::stop), "stop"); 
    eventManager.setAction(alg::createSignal(&act, & Actions::move), "move"); 
    eventManager.setAction(alg::createSignal(&act, & Actions::throwBomb), "throwBomb"); 
 
}

Player::~Player()
{
}

inline void Player::handleEvents(const event_t& event)
{
    eventManager.handleEvents(event);
}

inline void Player::update(const float& dt)
{
    animationManager.updateCurrentAnimation(dt);
    updateCoordinates(dt);
}

inline void Player::draw() 
{
    window->draw(attrib.sprite);
}

inline void Player::updateCoordinates(const float& dt)
{
    attrib.pos.x += attrib.v.x * dt;
    checkHorizontalCollisions(dt);

    attrib.pos.y += attrib.v.y * dt;
    checkVerticalCollisions(dt) ;

    attrib.sprite.setPosition(attrib.pos.x, attrib.pos.y);
}

inline void Player::checkHorizontalCollisions(const float& dt)
{
    for(wObjects_t::iterator it = wObjects->begin(); it != wObjects->end(); ++it) {
        if( ! isSameObject(it) && isCollided(it) ) {
            attrib.pos.x -= attrib.v.x * dt;
        }
    }
}

inline void Player::checkVerticalCollisions(const float& dt)
{
    for(wObjects_t::iterator it = wObjects->begin(); it != wObjects->end(); ++it) {
        if( ! isSameObject(it) && isCollided(it) ) {
            attrib.pos.y -= attrib.v.y * dt;
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
