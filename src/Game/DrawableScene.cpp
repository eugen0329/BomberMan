#include "Game/DrawableScene.hpp"

void DrawableScene::setFnInit(std::function<void(IWObjectPtr&)> init) 
{
	this->init = init;
}

DrawableScene::DrawableScene(unsigned int nLayers) 
{
	layers.resize(nLayers);
}

DrawableScene::~DrawableScene() 
{
	layers_t::iterator layersEnd = layers.end();
	for (layers_t::iterator l = layers.begin(); l != layersEnd; ++l ) {
		l->clear();
	}
}

void DrawableScene::handleEvents(const event_t& event) 
{
	WObjects::iterator limit = wObjects.end();
	for(WObjects::iterator ob = wObjects.begin(); ob != limit; ++ob ) {
		(*ob)->handleEvents(event);
	}
}

void DrawableScene::update(const float& dt) {
	WObjects::iterator limit = wObjects.end();
	for(WObjects::iterator ob = wObjects.begin(); ob != limit; ++ob ) {
		(*ob)->update(dt);
	}
}
void DrawableScene::draw() 
{

	layers_t::iterator layersEnd = layers.end();

	for (layers_t::iterator l = layers.begin(); l != layersEnd; ++l ) 
	{
		WObjects::iterator wObjectsEnd = (*l).end();
		for(WObjects::iterator ob = (*l).begin(); ob != wObjectsEnd; ++ob) {
			(*ob)->draw();
		}
	}
}


void DrawableScene::add(IWObjectPtr newObj, unsigned int layerIndex) 
{
	if(layerIndex >= layers.size()) return ;
	init(newObj);
	wObjects.push_back(newObj);
	layers[layerIndex].push_back(newObj);
}	

void DrawableScene::remove(IWObjectPtr removable) 
{
	using namespace std;
	WObjects::iterator item = find(begin(wObjects), end(wObjects), removable);
	if(item != wObjects.end()) {
		wObjects.erase(item);
	} else {
		return ;
	}
			if(notifyRemoval) notifyRemoval(removable->getAttr().groupID);
	layers_t::iterator layersEnd = layers.end();
	for (layers_t::iterator l = layers.begin(); l != layersEnd; ++l ) {
		WObjects::iterator item = find(begin(*l), end(*l), removable);
		if(item != l->end()) {
			l->erase(item);
			break;
		}
	}
	//
}	