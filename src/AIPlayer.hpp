#ifndef _AIPLAYER_HPP_
#define _AIPLAYER_HPP_

#include <vector>
#include "Person.hpp"

class AIPlayer : public Person {
private:
public:
    AIPlayer(GameMap&, std::vector<WorldsObject*>&);
    virtual ~AIPlayer();

    void changeState();
    void draw();
};

#endif /* end of include guard: _AIPLAYER_HPP_ */
