#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <vector>
#include "WorldsObjects/WorldsObject.hpp"
#include "WorldsObjects/Person.hpp"

#include "SFML/Graphics.hpp"

class Player : public Person {
private:
    typedef sf::Sprite sprite_t;
    typedef sf::Texture texture_t;

    texture_t texture;
    sprite_t sprite;
public:
    Player(GameMap &, std::vector<WorldsObject*> &, renderWindow_t &);
    virtual ~Player();

    void changeState();
    void draw();

};

#endif /* end of include guard: _PLAYER_HPP_ */
