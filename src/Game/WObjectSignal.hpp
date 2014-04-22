#ifndef _WOBJECTSIGNAL_HPP_
#define _WOBJECTSIGNAL_HPP_

#include <string>
//#include "Game/WObjects/IWorldsObject.hpp"

class IWorldsObject;

class WObjectSignal {
public:
	IWorldsObject* wObject;
    std::string action;

public:
    WObjectSignal(IWorldsObject& wObject, std::string action) : wObject(&wObject), action(action) {};

    virtual ~WObjectSignal() {}
};


#endif /* end of include guard: _WOBJECTSIGNAL_HPP_ */
