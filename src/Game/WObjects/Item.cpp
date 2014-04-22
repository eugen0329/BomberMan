#include "Game/WObjects/Item.hpp"

Item::Item()
{
}

Item::Item(GameMap& map, wObjects_t& wObjects, window_t& window) :
IWorldsObject(map, wObjects, window)
{

}


void Item::setSignal(Delegate* delegate, std::string signalName)
{
    if(signalName == "destroying") {
        this->destroyingSignal = *delegate;
    }
}
