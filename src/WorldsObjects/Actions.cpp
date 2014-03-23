#include "WorldsObjects/Actions.hpp"

Actions::Actions(properties_t & prop, AnimationManager & anim) : prop(&prop), anim(&anim)
{
}

Actions::~Actions()
{
}


void Actions::moveUp()
{
    prop->pos.y -= prop->step;
    prop->sprite.setPosition(prop->pos.x, prop->pos.y);
    anim->moveUp();
}

void Actions::moveDown()
{
    prop->pos.y += prop->step;
    prop->sprite.setPosition(prop->pos.x, prop->pos.y);
    anim->moveDown();
}

void Actions::moveRight()
{
    prop->pos.x += prop->step;
    prop->sprite.setPosition(prop->pos.x, prop->pos.y);
    anim->moveRight();
}

void Actions::moveLeft()
{
    prop->pos.x -= prop->step;
    prop->sprite.setPosition(prop->pos.x, prop->pos.y);
    anim->moveLeft();
}

