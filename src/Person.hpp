#ifndef _PERSON_HPP_
#define _PERSON_HPP_

#include "WorldsObject.hpp"

class Person : public WorldsObject {
private:
public:
    Person(GameMap&, std::vector<WorldsObject*>&);
    virtual ~Person();

    virtual void changeState();
    virtual void draw();

    virtual Vector2D<size_t> getPos(); 
};

#endif /* end of include guard: _PERSON_HPP_ */
