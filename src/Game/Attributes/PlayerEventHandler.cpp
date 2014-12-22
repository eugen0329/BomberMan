#include "Game/Attributes/PlayerEventHandler.hpp"

PlayerEventHandler::PlayerEventHandler(PlayerAttributes& attr, AnimationManager & anim) : 
attr(&attr), 
anim(&anim)
{
}

PlayerEventHandler::~PlayerEventHandler()
{
}

PlayerEventHandler::PlayerEventHandler() :
attr(NULL),
anim(NULL)
{
}

void PlayerEventHandler::setPlayerAttr(PlayerAttributes & attr)
{ 
    this->attr = &attr;
}

void PlayerEventHandler::setAnimationManager(AnimationManager& anim)
{
    this->anim = &anim;
}


//void PlayerEventHandler::move(float angle)
//{
//    dir.push_back(angle);
//    calcAngle();
//}

//void PlayerEventHandler::throwBomb(const std::string bombType)
//{
//    pWObject_t newBomb(new Bomb(*attr));
//
//    this->createWObject(newBomb);
//    addCollisionExclude(newBomb);
//}
// 
//void PlayerEventHandler::stop(float angle)
//{  
//    if(! dir.empty()) dir.erase(std::find(dir.begin(), dir.end(), angle));
//    calcAngle();
//}   

void PlayerEventHandler::calcAngle()
{
    if(dir.size() == 0) {                                   // if stopping
        attr->v.setComponents(0,0);
    } else if(dir.size() == 1) {                            // if starting to move
        attr->angle = dir.front();
        attr->v.setComponents(getVx(), getVy());
    } else {                                                // if turning
        for(directions_t::iterator it = dir.begin(); it!= dir.end(); it++) {
            if( (*it - Angle(1.0)).normalize() != attr->angle) {    // i
                attr->angle = alg::getAvarage(attr->angle, *(it)) ;
            } else {
                attr->angle = *it;
            }
        }
        attr->v.setComponents(getVx(),getVy());
    }
    if(attr->v.getAbs() == 0.0f) {
        changeAnimation("stand");
    } else {
        changeAnimation("move");
    }
}

void PlayerEventHandler::changeAnimation(const std::string& name)
{
    if(attr->angle.inPiRad() == 0.0) {
        anim->setCurrentAnimation(name + "Right");
    } else if(attr->angle.inPiRad() == 0.5) {
        anim->setCurrentAnimation(name + "Down");
    } else if(attr->angle.inPiRad() == 1.0) {
        anim->setCurrentAnimation(name + "Left");
    } else if(attr->angle.inPiRad() == 1.5) {
        anim->setCurrentAnimation(name + "Up");
    }
}

void PlayerEventHandler::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "create") {
        this->createWObject = *delegate;
    } 
}

void PlayerEventHandler::handleEvents(const event_t& event)
{
    handleKeyPressedEvents(event);
    handleKeyReleasedEvents(event);
}

void PlayerEventHandler::handleKeyPressedEvents(const event_t& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if(event.key.code == keys->up) {
            this->move(1.5f); 
        } else if(event.key.code == keys->down) {
            this->move(0.5f);
        } else if(event.key.code == keys->right) {
            this->move(0.0f);
        } else if(event.key.code == keys->left) {
            this->move(1.0f);
        } else if(event.key.code == keys->space) {
            this->throwBomb(std::string("SimpleBomb"));
        }   
    }
}

void PlayerEventHandler::handleKeyReleasedEvents(const event_t& event)
{
    if (event.type == sf::Event::KeyReleased) {
        if(event.key.code == keys->up) {
            this->stop(1.5f); 
        } else if(event.key.code == keys->down) {
            this->stop(0.5f);
        } else if(event.key.code == keys->right) {
            this->stop(0.0f);
        } else if(event.key.code == keys->left) {
            this->stop(1.0f);
        } else if(event.key.code == keys->space) {
        }
    }
}

void PlayerEventHandler::setKeyset(Keyset * keyset)
{
    keys = keyset;
}

void PlayerEventHandler::setAction(Delegate* delegate, std::string signalName)
{
    //if(signalName == "throwBomb") {
    //    this->throwBomb = *delegate;
    //} else if ( signalName == "move" ) {
    //    this->move = *delegate;
    //} else if ( signalName == "stop" ) {
    //    this->stop = *delegate;
    //} 
}



void PlayerEventHandler::setWObjects(wObjects_t& wObjects)
{
    this->wObjects = & wObjects;
}

void PlayerEventHandler::load(PlayerAttributes & attr, AnimationManager& anim)
{
    this->attr = &attr;
    this->anim = &anim;

    move = [&](float angle) {
        dir.push_back(angle);
        calcAngle();        
    };

    throwBomb = [&](const std::string&&) {
        std::cout << attr.pos.x;
        pWObject_t newBomb(new Bomb(attr));
        createWObject(newBomb);
        addCollisionExclude(newBomb);        
    };

    stop = [&](float angle) {

        if(! dir.empty()) dir.erase(std::find(dir.begin(), dir.end(), angle));
        calcAngle();
    };

}
 