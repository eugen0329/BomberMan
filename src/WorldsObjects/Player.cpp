#include "Player.hpp"

Player::Player(GameMap & map, std::vector<WorldsObject*> & wObjV, renderWindow_t & rendWindow) :  Person(map, wObjV, rendWindow)
{
    texture.loadFromFile("res/stone.gif");
    sprite.setTexture(texture);
}

Player::~Player()
{
}

void Player::changeState()
{
}

void Player::draw() 
{
    sprite.setPosition(50, 50 );
    renderWindow.draw(sprite);
}
