#include "Player.hpp"

Player::Player(GameMap & map, std::vector<WorldsObject*> & wObjV, renderWindow_t & rendWindow) :  
Actor(map, wObjV, rendWindow), animationManager(prop), act(prop, animationManager), eventManager(act)
{
	prop.step = 4;
	prop.pos.x = 0;
	prop.pos.y = 0;
    prop.width = 45;
    prop.heigth = 64;
    prop.texture.loadFromFile("res/Animations/tileSheet.png");
    prop.sprite.setTexture(prop.texture);
    prop.sprite.setPosition(0, 0 );
    prop.sprite.setOrigin(prop.width/2,prop.heigth/2);
    prop.sprite.setTextureRect(sf::IntRect(0,128,prop.width,prop.heigth ) );
}

Player::~Player()
{
}

void Player::update(float dt)
{
    eventManager.processEvents(dt);
    prop.sprite.setPosition(prop.pos.x, prop.pos.y);
}

void Player::draw() 
{
    pRenderWindow->draw(prop.sprite);
}

//void checkForCollisions()
//{
//    for(i = ) {
//        for (j = )
//    }
//}
