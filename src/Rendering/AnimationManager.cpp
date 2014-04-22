#include "Rendering/AnimationManager.hpp"

AnimationManager::AnimationManager() : attrib(NULL)
{
}

void AnimationManager::loadAnimations(xmlElement_t& element)
{
    currAnimation = element.Attribute("initialAnimation");
    AnimationManager::Initializer initializer(element, animations, *attrib);
    if(initializer.load() ) {
        exit(1);
    }
}

void AnimationManager::setObjectAttributes(IAttributes & attrib)
{
    this->attrib = &attrib;
}


AnimationManager::AnimationManager(xmlElement_t& element)
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

void AnimationManager::setCurrentAnimation(std::string newCurrAnimation)
{
    animations[currAnimation]->resetFrameIndex();
    currAnimation = newCurrAnimation;
}


void AnimationManager::updateCurrentAnimation(const float& dt)
{
    animations[currAnimation]->update(dt);
}

int AnimationManager::Initializer::load() const 
{
    Vector2D<int> pos;
    int width, heigth, nFrames, offset;
    float timeToFrame;
    std::string animName;

    xmlElement_t* animationIt = element->FirstChildElement("animation");
    while(animationIt) {
        animName = animationIt->Attribute("name");

        readFrameSizeAndLocations(*animationIt, pos, width, heigth);
        readFramesInformation(*animationIt, timeToFrame, nFrames, offset);

        (*animations)[animName] = new Animation(attrib->sprite, pos.x, pos.y, width, heigth, offset, nFrames, timeToFrame);
 
        animationIt = animationIt->NextSiblingElement("animation");
    }

    return 0;
}

void AnimationManager::Initializer::readFrameSizeAndLocations(const xmlElement_t& animationIt, Vector2D<int>& pos, int& width, int& heigth) const
{
    pos.x  = atoi(animationIt.Attribute("posX")  );
    pos.y  = atoi(animationIt.Attribute("posY")  );
    width  = atoi(animationIt.Attribute("width") );
    heigth = atoi(animationIt.Attribute("heigth"));      
}

void AnimationManager::Initializer::readFramesInformation(const xmlElement_t& animationIt, float& timeToFrame, int& nFrames, int& offset) const
{
    offset = atoi(animationIt.Attribute("offset"));
    timeToFrame = atof( animationIt.Attribute("timeToFrame") );
    nFrames     = atoi( animationIt.Attribute("nFrames") );
}

AnimationManager::Initializer::Initializer(xmlElement_t& element, animationsMap_t& animations, IAttributes& attrib)
{
    this->element = &element;   
    this->attrib  = &attrib;
    this->animations = &animations;
}

AnimationManager::Initializer::Initializer()// :
//IInitializer(),
//element(NULL),
//animations(NULL),
//attrib(NULL)
{
    this->element = NULL;   
    this->attrib  = NULL;
    this->animations = NULL;
}

AnimationManager::Initializer::~Initializer()
{
}
