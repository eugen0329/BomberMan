#include <iostream>
#include <SFML/Graphics.hpp>
#include "Matrix.hpp"
#include "Vector2D.hpp"
#include "GameMap.hpp"
#include "WorldsObjects/Player.hpp"
#include "WorldsObjects/WorldsObject.hpp"
#include "LWVector.hpp"
#include "Managers/ResourceManager.hpp" 
#include "Game.hpp" 
#include "StateStack.hpp"

#include <stack>
#include <string>

using namespace std;
typedef sf::Sprite sprite_t;
typedef sf::Texture texture_t;

int main(int argc, char* argv[])
{

    Game game;
    game.run();
//{{{

//}}} 

    return 0;
}



