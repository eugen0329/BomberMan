#ifndef DRAWABLESCENE_U009KARO
#define DRAWABLESCENE_U009KARO


#include <algorithm>
#include <vector>
#include <memory>

#include "Game/WObjects/IWorldsObject.hpp"

class IWorldsObject;

class DrawableScene {
	friend class GameLevel;

	typedef std::shared_ptr<IWorldsObject> IWObjectPtr;
	typedef std::vector<IWObjectPtr> WObjects;
	typedef std::vector<WObjects> layers_t;

	WObjects wObjects;
	layers_t layers;
	std::function<void(IWObjectPtr&)> init;
	std::function<void(int)> notifyRemoval;
public:
	void setFnInit(std::function<void(IWObjectPtr&)> init);
	DrawableScene(unsigned int nLayers = 2);
	~DrawableScene();
	void handleEvents(const event_t& event);
	void update(const float& dt);
	void draw();
	void add(IWObjectPtr newObj, unsigned int layerIndex);
	void remove(IWObjectPtr removable);
};



#endif /* end of include guard: DRAWABLESCENE_U009KARO */
