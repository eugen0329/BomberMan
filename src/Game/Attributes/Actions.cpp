#include "Game/Attributes/Actions.hpp"

Actions::Actions(PlayerAttributes& attrib, AnimationManager & anim) : 
attrib(&attrib), 
anim(&anim)
{
}

Actions::~Actions()
{
}

Actions::Actions() :
attrib(NULL),
anim(NULL)
{
}

void Actions::setPlayerAttr(PlayerAttributes & attrib)
{ 
    this->attrib = &attrib;
}

void Actions::setAnimationManager(AnimationManager& anim)
{
    this->anim = &anim;
}


void Actions::move(float angle)
{
    dir.push_back(angle);
    calculateAngle();
}

void Actions::throwBomb(const std::string bombType)
{
    pWObject_t newBomb(new Bomb(*attrib));

    this->createWObject(newBomb);
    addCollisionExclude(newBomb);
}
 
void Actions::stop(float angle)
{  
    if(! dir.empty()) dir.erase(std::find(dir.begin(), dir.end(), angle));
    calculateAngle();
}   

void Actions::calculateAngle()
{
    if(dir.size() == 0) {                                   // if stopping
        attrib->v.setComponents(0,0);
    } else if(dir.size() == 1) {                            // if starting to move
        attrib->angle = dir.front();
        attrib->v.setComponents(getVx(), getVy());
    } else {                                                // if turning
        for(directions_t::iterator it = dir.begin(); it!= dir.end(); it++) {
            if( (*it - Angle(1.0)).normalize() != attrib->angle) {    // i
                attrib->angle = alg::getAvarage(attrib->angle, *(it)) ;
            } else {
                attrib->angle = *it;
            }
        }
        attrib->v.setComponents(getVx(),getVy());
    }
    if(attrib->v.getAbs() == 0.0f) {
        changeAnimation("stand");
    } else {
        changeAnimation("move");
    }
}

void Actions::changeAnimation(const std::string& name)
{
    if(attrib->angle.inPiRad() == 0.0) {
        anim->setCurrentAnimation(name + "Right");
    } else if(attrib->angle.inPiRad() == 0.5) {
        anim->setCurrentAnimation(name + "Down");
    } else if(attrib->angle.inPiRad() == 1.0) {
        anim->setCurrentAnimation(name + "Left");
    } else if(attrib->angle.inPiRad() == 1.5) {
        anim->setCurrentAnimation(name + "Up");
    }
}

void Actions::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "create") {
        this->createWObject = *delegate;
    } else if (signalName == "addCollisionExclude") {
        this->addCollisionExclude = *delegate;
    }
}

void Actions::setWObjects(wObjects_t& wObjects)
{
    this->wObjects = & wObjects;
}
