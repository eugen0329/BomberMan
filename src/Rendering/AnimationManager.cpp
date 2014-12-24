#include "Rendering/AnimationManager.hpp"

AnimationManager::AnimationManager() : sprite(NULL)
{
}

void AnimationManager::loadAnimations(xmlElem_t& element)
{
    Vec2<int> pos;
    int width, heigth, nFrames, offset;
    float timeToFrame;
    std::string animName;

    xmlElem_t* it = element.FirstChildElement("animation");
    for( ;it ; it = it->NextSiblingElement("animation")) {

        pos.x       = atoi(it->Attribute("posX")  );
        pos.y       = atoi(it->Attribute("posY")  );
        width       = atoi(it->Attribute("width") );
        heigth      = atoi(it->Attribute("heigth"));    
        offset      = atoi(it->Attribute("offset"));
        timeToFrame = atof(it->Attribute("timeToFrame"));
        nFrames     = atoi(it->Attribute("nFrames"));

        animName = it->Attribute("name");
        animations[animName] = 
            new Animation(*sprite, pos.x, pos.y, width, heigth, offset, nFrames, timeToFrame);
    }

    currAnimation = element.Attribute("initialAnimation");
}

void AnimationManager::setSprite(sprite_t & sprite)
{
    this->sprite = &sprite;
}

AnimationManager::AnimationManager(xmlElem_t& element)
{
    loadAnimations(element);
}

AnimationManager::~AnimationManager()
{
    animationsMap_t::iterator it;
    for(it = animations.begin(); it != animations.end(); ++it) {
        delete (*it).second;
    }
}

void AnimationManager::setCurrent(std::string newCurrAnimation)
{
    currAnimation = newCurrAnimation;
}


void AnimationManager::updateCurrentAnimation(const float& dt)
{
    animations[currAnimation]->update(dt);
}

