#include "WorldsObjects/Actions.hpp"

Actions::Actions(properties_t & prop, AnimationManager & anim) : prop(&prop), anim(&anim)
{
}

Actions::~Actions()
{
}


void Actions::moveUp(float dt)
{
    prop->pos.y -= prop->step;
    //prop->sprite.setPosition(prop->pos.x, prop->pos.y);
    anim->moveUp(dt);
}

void Actions::moveDown(float dt)
{
    prop->pos.y += prop->step;
    //prop->sprite.setPosition(prop->pos.x, prop->pos.y);
    anim->moveDown(dt);
}

void Actions::moveRight(float dt)
{
    prop->pos.x += prop->step;
    //prop->sprite.setPosition(prop->pos.x, prop->pos.y);
    anim->moveRight(dt);
}

void Actions::moveLeft(float dt)
{
    prop->pos.x -= prop->step;
    //prop->sprite.setPosition(prop->pos.x, prop->pos.y);
    anim->moveLeft(dt);
}

