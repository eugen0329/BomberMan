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

    void updateFrame(ActionsIDs);
public:
    AnimationManager(properties_t &);
    virtual ~AnimationManager();



    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
};



#endif /* end of include guard: _ANIMATIONMANAGER_HPP_ */
