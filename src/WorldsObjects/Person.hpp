#ifndef _PERSON_HPP_
#define _PERSON_HPP_

#include <vector>
#include "WorldsObjects/WorldsObject.hpp"

class Person : public WorldsObject {
private:
public:
    Person(GameMap &, std::vector<WorldsObject*> &, renderWindow_t &);
    Person();
    virtual ~Person();

    virtual void changeState() = 0;
    virtual void draw() = 0;

    virtual Vector2D<size_t> getPos(); 
};

#endif /* end of include guard: _PERSON_HPP_ */
