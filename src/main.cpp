#include <iostream>
#include <SFML/Graphics.hpp>
#include "Application/Application.hpp" 

#include <exception>
#include <stack>
#include <string>

//#include "Common/Angle.hpp"

using namespace std;
typedef sf::Sprite sprite_t;
typedef sf::Texture texture_t;

int main(int argc, char* argv[])
{
    
    try {
        Application game; 
        game.run();
    }
    catch (const std::ios_base::failure  & e) { 
        std::cout << "Exception:" << std::endl << "    " << e.what();
    }

    
    return 0;
}



