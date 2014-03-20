#ifndef _RESOURCEMANAGER_HPP_
#define _RESOURCEMANAGER_HPP_

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

class ResourceManager {
private:
    typedef sf::Sprite sprite_t;
    typedef sf::Texture texture_t;

    typedef struct {
        std::vector<sprite_t> sprites;
    } resources_t;

    resources_t resources; 
    //std::string resPath;
    //std::string imageName;
public:
    ResourceManager(std::string resPath, std::vector<std::string> imagesNames);
    virtual ~ResourceManager();
};

#endif /* end of include guard: _RESOURCEMANAGER_HPP_ */

