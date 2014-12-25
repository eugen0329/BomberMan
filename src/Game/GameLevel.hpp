#ifndef _GAMELEVEL_HPP_
#define _GAMELEVEL_HPP_

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <exception>
#include <memory>
#include "TinyXML/tinyxml.h"

#include "Common/Algorithms.hpp"

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/Map/GameMap.hpp"
#include "Game/DrawableScene.hpp"

#include "Game/WObjects/Slug.hpp"
#include "Game/WObjects/Player.hpp"
#include "Game/WObjects/Wall.hpp"

class GameLevel {
private:
    class Signal;

    typedef std::function<void(DrawableScene*)> dererredAct;

    GameMap levelMap;
    DrawableScene scene;
    WObjects wObjects;
    window_t * window;

    std::queue<dererredAct> deferredQueue;
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

};

#endif /* end of include guard: _GAMELEVEL_HPP_ */
