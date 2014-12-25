#ifndef _GAMELEVEL_HPP_
#define _GAMELEVEL_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <exception>
#include <memory>
#include "TinyXML/tinyxml.h"


#include "Common/Algorithms.hpp"



#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/Map/GameMap.hpp"
#include "Game/DrawableScene.hpp"
#include "Game/WObjects/Player.hpp"
#include "Game/WObjects/Wall.hpp"

class GameLevel {
private:
    class Signal;
    typedef std::vector<WObjects> layers_t;
    typedef std::queue<Signal> signals_t;
    typedef std::function<void(DrawableScene*)> dererredAct;

    GameMap levelMap;

    DrawableScene scene;

    WObjects wObjects;
    layers_t layers;

    signals_t signals;

    window_t * window;

    std::stack<dererredAct> defSt;
    std::function<void(dererredAct&&)> pushDeferred;
public:
    GameLevel();
    GameLevel(window_t& );
    ~GameLevel();
	void setWindow(window_t*);

    void readObjectsFromXml(TiXmlElement*);

    void handleEvents(const event_t&);
    void update(const float&);
    void draw();

    void createActor(IWObjectPtr);
    void createItem(IWObjectPtr);
    void setBaseAttributes(IWObjectPtr&);

    void deleteObjectSignal( IWObjectPtr );
    void deleteObjectFromLayer( IWObjectPtr );
    void deleteObjectFromVector(IWObjectPtr );

    void createItemSignal(IWObjectPtr);
};

class GameLevel::Signal {
public:
    Signal(IWObjectPtr operand, std::string name) :
    operand(operand),
    name(name)
    {}
    IWObjectPtr operand;
    std::string name;
};

#endif /* end of include guard: _GAMELEVEL_HPP_ */
