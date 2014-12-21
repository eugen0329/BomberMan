#ifndef _GAMELEVEL_HPP_
#define _GAMELEVEL_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <exception>
#include <memory>

#include "Common/Algorithms.hpp"

#include "TinyXML/tinyxml.h"

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Player.hpp"
//#include "Game/WObjects/Bomb.hpp"
#include "Game/WObjects/Fire.hpp"
#include "Game/WObjects/Wall.hpp"
#include "Game/Map/GameMap.hpp"



template<class T>
bool operator == (std::shared_ptr<T> left, T* right)
{
    return left.get() == right;
}

typedef sf::Event event_t;
typedef sf::RenderWindow window_t;

typedef std::shared_ptr<IWorldsObject> pWObject_t;

typedef std::vector<pWObject_t> wObjects_t;

class GameLevel {
private:
    class Signal;
    typedef std::vector<wObjects_t> layers_t;
    typedef std::queue<Signal> signals_t;

    GameMap levelMap;
    wObjects_t wObjects;
    layers_t layers;
    signals_t signals;

    window_t * window;
public:
    GameLevel();
    GameLevel(window_t& );
    ~GameLevel();
	void setRenderWindow(window_t*);

    void readObjectsFromXml(TiXmlElement*);

    void handleEvents(const event_t&);
    void update(const float&);
    void draw();

    void createActor(pWObject_t);
    void createItem(pWObject_t);
    void setBaseAttributes(pWObject_t&);

    void deleteObjectSignal( pWObject_t );
    void deleteObjectFromLayer( pWObject_t );
    void deleteObjectFromVector(pWObject_t );

    void createItemSignal(pWObject_t);
};

class GameLevel::Signal {
public:
    Signal(pWObject_t operand, std::string name) :
    operand(operand),
    name(name)
    {}
    pWObject_t operand;
    std::string name;
};

#endif /* end of include guard: _GAMELEVEL_HPP_ */
