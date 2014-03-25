#ifndef _ANIMATIONMANAGER_HPP_
#define _ANIMATIONMANAGER_HPP_

#include <vector>

#include <SFML/Graphics.hpp>

#include "WorldsObjects/ObjectProperties.hpp"
#include "Managers/Animation.hpp"

//typedef sf::RenderWindow 

class AnimationManager {
private:
    int   actionID;

    std::vector<Animation*> animations;
    properties_t * prop;
    enum ActionsIDs {
        Up,
        Down,
        Right,
        Left
    };

    void updateFrame(float, ActionsIDs);
public:
    AnimationManager(properties_t &);
    virtual ~AnimationManager();



    void inline moveUp(float dt)
    {
        updateFrame(dt, Up);
    }
    
    void inline moveDown(float dt)
    {
        updateFrame(dt, Down);
    }
    
    void inline moveRight(float dt)
    {
        updateFrame(dt, Right);
    }
    
    void inline moveLeft(float dt)
    {
        updateFrame(dt, Left);
    }
};



#endif /* end of include guard: _ANIMATIONMANAGER_HPP_ */
