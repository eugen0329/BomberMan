#include <iostream>
#include <SFML/Graphics.hpp>

#include "Application.hpp" 

#include <exception>
#include <stack>
#include <string>

std::function<void()> a;

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
