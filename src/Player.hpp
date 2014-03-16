#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <vector>
#include "Person.hpp"

class Player : public Person {
private:
public:
    Player(GameMap&, std::vector<WorldsObject*>&);
    virtual ~Player();

    void changeState();
    void draw();

};

#endif /* end of include guard: _PLAYER_HPP_ */
