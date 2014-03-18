#include <iostream>
#include <SFML/Graphics.hpp>
#include "Matrix.hpp"
#include "Vector2D.hpp"
#include "GameMap.hpp"
#include "WorldsObjects/Person.hpp"
#include "WorldsObjects/Player.hpp"
#include "WorldsObjects/AIPlayer.hpp"
#include "WorldsObjects/WorldsObject.hpp"
#include "LWVector.hpp"
#include "ResourceManager.hpp" 
#include "Game.hpp" 
#include "GameStates/StateStack.hpp"

#include <stack>


using namespace std;

int main(int argc, char* argv[])
{
    Matrix<char> matrix(1,1);
    matrix[0][0] = 'a';
    cout << matrix[0][0] << endl;

//{{{
    //const unsigned int xWindSize = 800;
    //const unsigned int yWindSize = 600;
    //const sf::Color black(0,0,0);
    //
    //// Create window of the application
    //// sf::VideoMode (x, y, bitsPerPixel)
    //sf::RenderWindow window(sf::VideoMode(xWindSize, yWindSize, 32), "\\o");
    //window.setVerticalSyncEnabled(true);

    //sf::RectangleShape rectangle;
    //rectangle.setSize(sf::Vector2f(50, 50));
    ////rectangle.setOutlineThickness(0);
    ////rectangle.setOutlineColor(sf::Color::Red);
    //rectangle.setFillColor(sf::Color::Blue);
    //rectangle.setOrigin( xWindSize / 2, yWindSize / 2);
    //    rectangle.setPosition(xWindSize / 2, yWindSize / 2);

    //while(window.isOpen()) {
    //    
    //    // handle events
    //    sf::Event event;
    //    while(window.pollEvent(event)) {
    //        // Closing when ESC or close button is pushed
    //        if( (event.type == sf::Event::Closed) ||
    //            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
    //            window.close();
    //            break;
    //        }
    //    }
    //    
    //    // sf::RenderWindow::clear(fillColor)
    //    window.clear(sf::Color::Black);

    //    rectangle.setPosition(xWindSize , yWindSize );

    //    window.draw(rectangle);
    //    window.display();
    //    
    //}
//}}} 

    return 0;
}



