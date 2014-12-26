#ifndef _FIRE_HPP_
#define _FIRE_HPP_

#include <cstdint> /* int8_t */

#include "TinyXML/tinyxml.h"

#include "Common/BasicTypes.hpp"

#include "Common/Vec2.hpp"
#include "Common/Algorithms.hpp"

#include "Game/WObjects/IWorldsObject.hpp"
#include "Game/WObjects/Item.hpp"
#include "Game/DrawableScene.hpp"
#include "Rendering/AnimationManager.hpp"

class Blow : public Item {
protected:
    struct  Attributes : public Item::Attributes {
        Vec2<float> origin;
        float lifeTime;
        float actLifeTime;
        int damage;
        texture_t texture;
        sprite_t  sprite;
    };

    Blow::Attributes attr;
    Delegate destroyingSignal;
    Delegate createSignal;
    AnimationManager animationManager;
public:
    enum class STYLE : std::int8_t {
        FLAME,
        BLOW, 
        SLUG_BLOW
    };

    Blow();
    Blow(const Vec2<float>& pos, int groupId, STYLE style);
    
    virtual ~Blow();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void draw();
    void loadAttr(xmlElem_t& elem);
    virtual IWorldsObject::Attributes& getAttr() 
    {
        return attr;
    }

    virtual void addCollision(Collision) {}
    virtual void setWorldObjects(WObjects&);
    void load(xmlElem_t& elem);
};

#endif /* end of include guard: _FIRE_HPP_ */
