#include <iostream>
#include <SFML/Graphics.hpp>

#include "Application.hpp" 

#include <exception>
#include <stack>
#include <string>


int main(int argc, char* argv[])
{
    try {
        Application game; 
        game.run();
    }
    catch (const std::ios_base::failure& e) { 
        std::cout << "Ios base exception:" << std::endl << "    " << e.what();
    }
    catch (const std::invalid_argument& e) { 
        std::cout << "Invalid arg:" << std::endl << "    " << e.what();
    }
  
    return 0;
}
