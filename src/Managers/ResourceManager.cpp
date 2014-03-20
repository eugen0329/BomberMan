#include "ResourceManager.hpp"

ResourceManager::ResourceManager(std::string resPath, std::vector<std::string> imagesNames)
{
    texture_t texture;

    resources.sprites.resize(imagesNames.size());
    for(unsigned int i = 0; i < imagesNames.size(); i++) {
        texture.loadFromFile(resPath + imagesNames[i]);
        resources.sprites[i].setTexture(texture);
    }
}

ResourceManager::~ResourceManager()
{
}

