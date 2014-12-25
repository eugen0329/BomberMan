#include "Game/WObjects/Item.hpp"

Item::Item()
{
}

Item::Item(WObjects& wObjects, window_t& window) :
IWorldsObject(wObjects, window)
{

}


void Item::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    }
}
