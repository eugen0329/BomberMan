#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <vector>
#include "WorldsObjects/WorldsObject.hpp"
#include "WorldsObjects/Person.hpp"

class Player : public Person {
private:
public:
    Player(GameMap &, std::vector<WorldsObject*> &, renderWindow_t &);
    virtual ~Player();

    void changeState() const;
    void draw() const;

};

#endif /* end of include guard: _PLAYER_HPP_ */
