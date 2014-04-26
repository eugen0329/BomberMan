#ifndef _IWORLDSOBJECT_HPP_
#define _IWORLDSOBJECT_HPP_

#define LIB_DIR inc

#include <vector>
#include "queue"
#include <string>
#include <cstdio>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>

#include "Game/WObjectSignal.hpp"

#include "Common/Vector2D.hpp"
#include "Common/Delegate.hpp"
#include "Game/Map/GameMap.hpp"
#include "Game/Attributes/IAttributes.hpp"

typedef std::queue<WObjectSignal*> signals_t;
class IWorldsObject;

typedef sf::Event event_t;
typedef std::vector<IWorldsObject*> wObjects_t;
typedef sf::RenderWindow window_t;

class IWorldsObject {
protected:

    //bool solid;

    GameMap* map;
    wObjects_t* wObjects;
    window_t * window;
    Delegate destroyingSignal;
    //signals_t* signals;
public:
    //std::string objectID;

    //typedef void (GameLevel::*functPtr_t)(IWorldsObject*);
    //functPtr_t popThisObject;
    // void setFunct(functPtr_t funct)
    //{
    //    this->popThisObject = funct;
    //}

public:

    IWorldsObject(GameMap&, wObjects_t &, window_t &);
    IWorldsObject();
    virtual ~IWorldsObject();

    //inline bool isSolid()
    //{
    //    return solid;
    //}
    

    void setMap(GameMap&);
    void setWorldsObjectsVector(wObjects_t&);
    void setRenderWindow(window_t&);
    //void setSignalsQueue(signals_t&);
    virtual void setSignal(Delegate *, std::string) = 0;

    virtual void handleCollisions() = 0;
    virtual void checkCollisions() = 0;

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0; 
    virtual IAttributes getAttributes() = 0;

    //inline virtual void setObjectID(std::string newID)
    //{
    //    objectID = newID;
    //}

};

#endif /* end of include guard: _IWORLDSOBJECT_HPP_ */
