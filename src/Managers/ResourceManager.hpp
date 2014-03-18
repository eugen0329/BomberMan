#ifndef _RESOURCEMANAGER_HPP_
#define _RESOURCEMANAGER_HPP_

#include <string>

#include <SFML/Graphics.hpp>

class ResourceManager {
private:
    typedef sf::Sprite sprite_t;
    typedef sf::Texture texture_t;

    typedef struct {
        sprite_t sprite;
    } resources_t;


    resources_t resources; 
    //std::string resPath;
    //std::string imageName;
public:
    ResourceManager(std::string, std::string);
    virtual ~ResourceManager();
};

#endif /* end of include guard: _RESOURCEMANAGER_HPP_ */
