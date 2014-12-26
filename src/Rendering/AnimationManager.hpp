#ifndef _ANIMATIONMANAGER_HPP_
#define _ANIMATIONMANAGER_HPP_

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Common/BasicTypes.hpp"

#include "Common/Algorithms.hpp"
#include "Common/Interfaces/IEventManager.hpp"
#include "Common/Interfaces/IInitializer.hpp"
#include "Common/Vec2.hpp"

#include "Rendering/Animation.hpp"

class AnimationManager {
private:
    typedef std::map<std::string, Animation*> animationsMap_t;

    std::string currAnimation;
    animationsMap_t animations;
    sprite_t * sprite;
public:
    AnimationManager();
    AnimationManager(xmlElem_t &);
    virtual ~AnimationManager();

    void setCurrent(std::string);
    void updateCurrentAnimation(const float&);

    void setSprite(sprite_t&);
    void loadAnimations(xmlElem_t&);
};

#endif /* end of include guard: _ANIMATIONMANAGER_HPP_ */

