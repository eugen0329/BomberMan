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
public:
	void setFnInit(std::function<void(IWObjectPtr&)> init) {
		this->init = init;
	}
	DrawableScene(unsigned int nLayers = 2) {
		layers.resize(nLayers);
	}
	~DrawableScene() {
		layers_t::iterator layersEnd = layers.end();
		for (layers_t::iterator l = layers.begin(); l != layersEnd; ++l ) {
			l->clear();
		}
	}

	void handleEvents(const event_t& event) {
		WObjects::iterator limit = wObjects.end();
		for(WObjects::iterator ob = wObjects.begin(); ob != limit; ++ob ) {
			(*ob)->handleEvents(event);
		}
	}

	void update(const float& dt) {
		WObjects::iterator limit = wObjects.end();
		for(WObjects::iterator ob = wObjects.begin(); ob != limit; ++ob ) {
			(*ob)->update(dt);
		}
	}
	void draw() {

		layers_t::iterator layersEnd = layers.end();

		for (layers_t::iterator l = layers.begin(); l != layersEnd; ++l ) {
			WObjects::iterator wObjectsEnd = (*l).end();
			for(WObjects::iterator ob = (*l).begin(); ob != wObjectsEnd; ++ob) {
				(*ob)->draw();
			}
		}
	}


	void add(IWObjectPtr newObj, unsigned int layerIndex) {
		if(layerIndex >= layers.size()) return ;
		init(newObj);
		wObjects.push_back(newObj);
		layers[layerIndex].push_back(newObj);
	}	

	void remove(IWObjectPtr removable) {
		using namespace std;
		WObjects::iterator item = find(begin(wObjects), end(wObjects), removable);
		if(item != wObjects.end()) {
			wObjects.erase(item);
		} else {
			return ;
		}
				
		layers_t::iterator layersEnd = layers.end();
		for (layers_t::iterator l = layers.begin(); l != layersEnd; ++l ) {
			WObjects::iterator item = find(begin(*l), end(*l), removable);
			if(item != l->end()) {
				l->erase(item);
				break;
			}
		}
	}	
};



#endif /* end of include guard: DRAWABLESCENE_U009KARO */
