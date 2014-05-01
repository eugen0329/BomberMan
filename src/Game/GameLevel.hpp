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
#include "XMLParser/tinyxml.h"

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Player.hpp"
//#include "Game/WObjects/Bomb.hpp"
#include "Game/WObjects/Wall.hpp"
#include "Game/Map/GameMap.hpp"



typedef sf::Event event_t;
typedef sf::RenderWindow window_t;

typedef std::shared_ptr<IWorldsObject> pWObject_t;

typedef std::vector<pWObject_t> wObjects_t;

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

    void createActor(pWObject_t);
    void createItem(pWObject_t);
    void setBaseAttributes(pWObject_t&);

    void deleteObjectSignal( pWObject_t );
    void deleteObjectFromLayer( pWObject_t) ;
    void deleteObjectFromVector( pWObject_t);

    void createItemSignal(pWObject_t);
};

#endif /* end of include guard: _GAMELEVEL_HPP_ */
