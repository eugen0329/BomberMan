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

void Actions::setPlayerAttributes(PlayerAttributes & attrib)
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
    TiXmlDocument* xmlFile = alg::openXmlFile("res/Bomb.xml"); 
    TiXmlElement* bombAttributes = alg::getXmlElement(xmlFile, {"Bombs", bombType} );
    this->createWObject(dynamic_cast<IWorldsObject*>(new Bomb(*bombAttributes, *attrib)));
    delete xmlFile;
    this->createWObject(dynamic_cast<IWorldsObject*>(new Bomb(*attrib)));
}
 
void Actions::stop(float angle)
{  
    dir.erase(std::find(dir.begin(), dir.end(), angle));
    calculateAngle();
}   

void Actions::calculateAngle()
{
    if(dir.size() == 0) {                                   // if stopping
        attrib->v.setCoordinates(0,0);
    } else if(dir.size() == 1) {                            // if starting to move
        attrib->angle = dir.front();
        attrib->v.setCoordinates(getVx(), getVy());
    } else {                                                // if turning
        for(directions_t::iterator it = dir.begin(); it!= dir.end(); it++) {
            if( (*it - Angle(1.0)).correctAngle() != attrib->angle) {    // i
                attrib->angle = alg::getAvarage(attrib->angle, *(it)) ;
            } else {
                attrib->angle = *it;
            }
        }
        attrib->v.setCoordinates(getVx(),getVy());
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
    }
}
