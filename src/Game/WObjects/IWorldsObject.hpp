#ifndef _IWORLDSOBJECT_HPP_
#define _IWORLDSOBJECT_HPP_

#include <vector>
#include <string>
#include <cstdio>
#include <memory>
#include <functional>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System.hpp>

#include "Common/BasicTypes.hpp"

#include "Common/Algorithms.hpp"
#include "Common/Vec2.hpp"
#include "Common/Delegate.hpp"
#include "Game/Map/GameMap.hpp"



class DrawableScene;

class IWorldsObject {
protected:
    struct Attributes : public BaseShape {
        bool solid;
        bool harmful;
        int groupID;

        Attributes(bool solid = true, int groupID = 0) : solid(solid), groupID(groupID) {}
        ~Attributes() {}
        bool isSolid();
        bool isHarmful();
        int getGroupID();
    };
    typedef  IWorldsObject::Attributes Collision;

    pushDef_t pushDeferred;

    std::function<void(IWObjectPtr)> deleteWObject; 


    WObjects* wObjects;
    window_t * window;
    Delegate destroyingSignal;

public:

    void setFnPushDeferred(pushDef_t&& pushDeferred);


    IWorldsObject(WObjects &, window_t &);
    IWorldsObject();
    virtual ~IWorldsObject();

    void setWindow(window_t&);
    virtual void setSignal(Delegate *, std::string) = 0;
    virtual void setWorldObjects(WObjects&) = 0;

    virtual void addCollision(Collision) = 0;

    virtual void handleEvents(const event_t&) = 0;
    virtual void update(const float&) = 0;
    virtual void draw() = 0; 

    virtual Attributes& getAttr() = 0;

};

#endif /* end of include guard: _IWORLDSOBJECT_HPP_ */
