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
    		pushDeferred(new Deferred<void>([&]() {
    			if(typeid(stateStack->top()) == typeid(GameMenuState*)) return ;
    			stateStack->push(new GameMenuState);
    		}));
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

void GameState::load(window_t &window, StateStack& st, std::function<void(IDeferred*)>& fn)
{
    this->window = &window;
    pushDeferred = fn;
    stateStack = &st;
    level = new GameLevel(window);
}
