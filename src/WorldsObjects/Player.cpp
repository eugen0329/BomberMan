#include "Player.hpp"

Player::Player(GameMap & map, std::vector<WorldsObject*> & wObjV, renderWindow_t & rendWindow) :  
Person(map, wObjV, rendWindow), eventManager(prop)
{
	prop.step = 2;
	prop.x = 0;
	prop.y = 0;
    prop.texture.loadFromFile("res/stone.gif");
    prop.sprite.setTexture(prop.texture);
    
}

Player::~Player()
{
}

void Player::update(float dt)
{
    eventManager.processEvents();
}

void Player::draw() 
{
    prop.sprite.setPosition(prop.x, prop.y);
    renderWindow.draw(prop.sprite);
}
