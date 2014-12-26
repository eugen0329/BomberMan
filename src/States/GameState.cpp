#include "States/GameState.hpp"

GameState::GameState()
{
	std::cerr << "in game\n";
}

GameState::~GameState()
{
    delete level;
}

void GameState::handleEvents(const event_t& event)
{
    level->handleEvents(event);
    if(event.type == sf::Event::KeyPressed) {
    	if(event.key.code == sf::Keyboard::Escape) {
    		pushDeferred( [this] (StateStack* st) {
    			if(typeid(st->top()) == typeid(GameMenuState*)) return ;
    			st->push(IAppStatePtr(new GameMenuState));
    		});
    	}
    }
}

void GameState::update(const float& dt)
{
    level->update(dt);
}

void GameState::draw()
{
   
    window->clear(sf::Color::White);
    level->draw();
}

void GameState::setWindow(window_t& window)
{
    this->window = &window;
    level = new GameLevel(window);
}
