#include "ResourceManager.hpp"

ResourceManager::ResourceManager(std::string resPath, std::string imageName)
{
    texture_t texture;

    texture.loadFromFile(resPath + imageName);
    resources.sprite.setTexture(texture);
}

ResourceManager::~ResourceManager()
{
}
