#include "WorldsObjects/Actions.hpp"

Actions::Actions(properties_t & prop) : prop(&prop)
{
}

Actions::~Actions()
{
}


void Actions::moveUp()
{
    prop->pos.y -= prop->step;
    prop->sprite.setPosition(prop->pos.x, prop->pos.y);
}

void Actions::moveDown()
{
    prop->pos.y += prop->step;
    prop->sprite.setPosition(prop->pos.x, prop->pos.y);
}

void Actions::moveRight()
{
    prop->pos.x += prop->step;
    prop->sprite.setPosition(prop->pos.x, prop->pos.y);
}

void Actions::moveLeft()
{
    prop->pos.x -= prop->step;
    prop->sprite.setPosition(prop->pos.x, prop->pos.y);
}

