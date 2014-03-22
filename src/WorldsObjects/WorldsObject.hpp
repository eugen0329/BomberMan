#ifndef _WORLDSOBJECT_HPP_
#define _WORLDSOBJECT_HPP_

#define LIB_DIR inc

#include <vector>
#include <cstdio>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Vector2D.hpp"
#include "GameMap.hpp"

typedef sf::Event event_t;

class WorldsObject {
protected:
    typedef sf::RenderWindow renderWindow_t;

    GameMap& map;
    std::vector<WorldsObject*>& worldsObjectVector;
    renderWindow_t& renderWindow;

    Vector2D<size_t> pos;
public:
    WorldsObject(GameMap&, std::vector<WorldsObject*> &, renderWindow_t & );
    virtual ~WorldsObject();

    virtual void update(float) = 0;
    virtual void draw() = 0;
    virtual Vector2D<size_t> getPos() = 0; 

};

#endif /* end of include guard: _WORLDSOBJECT_HPP_ */
