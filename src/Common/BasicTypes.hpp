#ifndef BASICTYPES_IWGQJS8L
#define BASICTYPES_IWGQJS8L

#include <functional>
#include <memory>

class IWorldsObject;
class DrawableScene;


typedef sf::Event event_t;
typedef sf::RenderWindow window_t;
typedef std::shared_ptr<IWorldsObject> IWObjectPtr;
typedef std::vector<IWObjectPtr> WObjects;
typedef std::function<void(DrawableScene*)> dererredAct;
typedef std::function<void(dererredAct)> pushDef_t;

#endif /* end of include guard: BASICTYPES_IWGQJS8L */
