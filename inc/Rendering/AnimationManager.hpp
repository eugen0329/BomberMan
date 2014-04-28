#ifndef _ANIMATIONMANAGER_HPP_
#define _ANIMATIONMANAGER_HPP_

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Common/Interfaces/IEventManager.hpp"
#include "Common/Interfaces/IInitializer.hpp"
#include "Common/Vector2D.hpp"

#include "Rendering/Animation.hpp"

class AnimationManager {
private:
    typedef std::map<std::string, Animation*> animationsMap_t;
    typedef sf::Sprite sprite_t;
    class Initializer;

    std::string currAnimation;

    animationsMap_t animations;
    //IAttributes * attrib;
    sprite_t * sprite;

//private:
public:
    AnimationManager();
    AnimationManager(xmlElement_t &);
    virtual ~AnimationManager();

    void setCurrentAnimation(std::string);
    void updateCurrentAnimation(const float&);

    //void setObjectAttributes(IAttributes &);
    void setSprite(sprite_t&);
    void loadAnimations(xmlElement_t&);
};


class AnimationManager::Initializer : public IInitializer {
private:
    mutable animationsMap_t* animations; 
    mutable sprite_t* sprite; 

    void readFrameSizeAndLocations(const xmlElement_t&, Vector2D<int>&, int&, int&) const;
    void readFramesInformation(const xmlElement_t&, float&, int&, int&) const;
public:
    Initializer();
    Initializer(xmlElement_t&, animationsMap_t&, sprite_t&);
    virtual ~Initializer();
    
    int load() const;
    
};


#endif /* end of include guard: _ANIMATIONMANAGER_HPP_ */

