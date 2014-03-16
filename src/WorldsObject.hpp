#ifndef _WORLDSOBJECT_HPP_
#define _WORLDSOBJECT_HPP_

#define LIB_DIR inc

#include <vector>
#include <cstdio>

#include "Vector2D.hpp"
#include "GameMap.hpp"

class WorldsObject;

class WorldsObject {
protected:
    const GameMap& map;
    const std::vector<WorldsObject*>& worldsObjectVector;
    Vector2D<size_t> pos;
public:
    WorldsObject(GameMap&, std::vector<WorldsObject*> & );
    virtual ~WorldsObject();

    virtual void changeState() = 0;
    virtual void draw() = 0;
    virtual Vector2D<size_t> getPos() = 0; 

};

#endif /* end of include guard: _WORLDSOBJECT_HPP_ */
