#ifndef _KEYSET_HPP_
#define _KEYSET_HPP_

#include <string>
#include "SFML/System.hpp"

class Keyset {
private:
    typedef sf::Keyboard Set;
public:
    enum SetID {
        WSDASpace = 1,
        NUM8564Right = 2 
    };
    Keyset(SetID setID) 
    {
        if(setID == WSDASpace) {
            up = Set::W;
            down = Set::S;
            right = Set::D;
            left = Set::A;
            space = Set::Space;
        } else if(setID == NUM8564Right) {
            up = Set::Numpad8;
            down = Set::Numpad5;
            right = Set::Numpad6;
            left = Set::Numpad4;
            space = Set::Return;
        }
    }
    Keyset(const Keyset& second) 
    {   
        up    = second.up;
        down  = second.down;
        right = second.right;
        left  = second.left;
        space = second.space;
    }
    Set::Key up;
    Set::Key down;
    Set::Key right;
    Set::Key left;
    Set::Key space;

        
};


#endif /* end of include guard: _KEYSET_HPP_ */
