#ifndef _GAMELEVEL_HPP_
#define _GAMELEVEL_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <exception>

#include "Common/Algorithms.hpp"
#include "XMLParser/tinyxml.h"

#include "Game/WObjects/Player.hpp"
#include "Game/WObjects/Bomb.hpp"
#include "Game/WObjects/Wall.hpp"
#include "Game/Map/GameMap.hpp"
#include "Game/WObjects/IWorldsObject.hpp"


typedef sf::Event event_t;
typedef sf::RenderWindow window_t;

typedef std::vector<IWorldsObject*> wObjects_t;

typedef std::queue<WObjectSignal*> signals_t;

class GameLevel {
private:
    typedef std::vector<wObjects_t> layers_t;
    GameMap stageMap;
    wObjects_t wObjects;
    layers_t drawableLayers;

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

    void createActor(IWorldsObject*);
    void createItem(IWorldsObject*);
    void setBaseAttributes(IWorldsObject *&);

    void deleteObjectSignal( IWorldsObject* );
    void deleteObjectFromLayer( IWorldsObject *) ;
    void deleteObjectFromVector( IWorldsObject *);

    void createItemSignal(IWorldsObject*);
    bool hasCollisions(IWorldsObject*);
};

#endif /* end of include guard: _GAMELEVEL_HPP_ */
