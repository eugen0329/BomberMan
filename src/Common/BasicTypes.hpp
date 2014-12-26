#ifndef BASICTYPES_IWGQJS8L
#define BASICTYPES_IWGQJS8L

#include <functional>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "tinyxml.h"

class IWorldsObject;
class DrawableScene;
class IAppState;
class StateStack;

typedef sf::Event event_t;
typedef sf::RenderWindow window_t;
typedef std::shared_ptr<IWorldsObject> IWObjectPtr;
typedef std::vector<IWObjectPtr> WObjects;
typedef std::function<void(DrawableScene*)> dererredAct;
typedef std::function<void(dererredAct)> pushDef_t;
typedef TiXmlElement xmlElem_t;
typedef sf::RenderTexture renderableTexture_t;
typedef sf::Texture texture_t;
typedef sf::Sprite sprite_t;
typedef std::shared_ptr<IAppState> IAppStatePtr;

typedef std::function<void(StateStack*)> deferred_t;
typedef std::function<void(deferred_t)> pushDeferred_t;

#endif /* end of include guard: BASICTYPES_IWGQJS8L */
