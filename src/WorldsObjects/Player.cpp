#include "Player.hpp"

Player::Player(GameMap & map, std::vector<WorldsObject*> & wObjV, renderWindow_t & rendWindow) :  
Actor(map, wObjV, rendWindow), animationManager(prop), act(prop, animationManager), eventManager(act)
{
	prop.step = 2;
	prop.pos.x = 0;
	prop.pos.y = 0;
    prop.texture.loadFromFile("res/tileSheet.png");
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
    prop.sprite.setPosition(prop.pos.x, prop.pos.y);
    renderWindow.draw(prop.sprite);
}
