#ifndef _RESOURCEMANAGER_HPP_
#define _RESOURCEMANAGER_HPP_

#include <string>

class ResourceManager {
private:
    std::string resPath;
public:
    ResourceManager(std::string);
    virtual ~ResourceManager();
};

#endif /* end of include guard: _RESOURCEMANAGER_HPP_ */
