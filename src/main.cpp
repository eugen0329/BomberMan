#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp" 
#include "WorldsObjects/ObjectProperties.hpp" 
#include "Managers/AnimationManager.hpp" 
#include "GameMap.hpp" 

#include <stack>
#include <string>

using namespace std;
typedef sf::Sprite sprite_t;
typedef sf::Texture texture_t;

int main(int argc, char* argv[])
{

    Game game; game.run();
//{{{
    //sf::RenderWindow window( sf::VideoMode(600, 400), "Test!");
    //
    //while(window.isOpen()) {
    //    sf::Event event;
    //    while(window.pollEvent(event)) {
    //        if( (event.type == sf::Event::Closed) ||
    //            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
    //            window.close();
    //            break;
    //        }
    //    }

    //
    //    window.clear(sf::Color::White);
    //    

    //    window.display();
    //}
//}}} 

    return 0;
}



