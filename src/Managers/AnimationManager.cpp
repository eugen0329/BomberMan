#include "Managers/AnimationManager.hpp"

AnimationManager::AnimationManager(properties_t & prop) : prop(&prop)
{
    animations.push_back(new Animation(this->prop->sprite, 0,  192, 45, 64, 3));
    animations.push_back(new Animation(this->prop->sprite, 0,  0, 45, 64, 3));
    animations.push_back(new Animation(this->prop->sprite, 0, 128, 45, 64, 3));
    animations.push_back(new Animation(this->prop->sprite, 0, 64,  45, 64, 3));
    actionID = Down;
    updateFrame(Down);
}

AnimationManager::~AnimationManager()
{
}

void AnimationManager::moveUp()
{
    updateFrame(Up);
}

void AnimationManager::moveDown()
{
    updateFrame(Down);
}

void AnimationManager::moveRight()
{
    updateFrame(Right);
}

void AnimationManager::moveLeft()
{
    updateFrame(Left);
}

void AnimationManager::updateFrame(ActionsIDs currActionID)
{
    if(actionID != currActionID) {
        animations[actionID]->resetFrameNumber();
        actionID = currActionID;
    }
    animations[actionID]->update();
}
