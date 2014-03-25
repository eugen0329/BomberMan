#include "Managers/AnimationManager.hpp"

AnimationManager::AnimationManager(properties_t & prop) : prop(&prop)
{
    animations.push_back(new Animation(this->prop->sprite, 0,  192, 45, 64, 3));
    animations.push_back(new Animation(this->prop->sprite, 0,  0, 45, 64, 3));
    animations.push_back(new Animation(this->prop->sprite, 0, 128, 45, 64, 3));
    animations.push_back(new Animation(this->prop->sprite, 0, 64,  45, 64, 3));
    actionID = Down;
    //updateFrame(Down);
}

AnimationManager::~AnimationManager()
{
    for(unsigned int i = 0; i < animations.size(); i++) {
        delete animations[i];
    }
}

void AnimationManager::updateFrame(float dt, ActionsIDs currActionID)
{
    if(actionID != currActionID) {
        animations[actionID]->resetFrameIndex();
        actionID = currActionID;
    }
    animations[currActionID]->update(dt);
}
