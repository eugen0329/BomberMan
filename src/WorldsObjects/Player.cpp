#include "Player.hpp"

Player::Player(GameMap & map, std::vector<WorldsObject*> & wObjV, renderWindow_t & rendWindow) :  Person(map, wObjV, rendWindow)
{
}

Player::~Player()
{
}

void Player::changeState() const
{
}

void Player::draw() const
{
}
