#include "States/GameMenuState.hpp"

GameMenuState::GameMenuState()
{
}

GameMenuState::~GameMenuState()
{
    delete resumeBtn;
    delete exitBtn;
}  

void GameMenuState::handleEvents(const event_t& event)
{
    resumeBtn->handleEvents(event);
    exitBtn->handleEvents(event);
}

void GameMenuState::update(const float& dt)
{
}

void GameMenuState::draw()
{
    window->draw(bgSprite);
    resumeBtn->draw();
    exitBtn->draw();
}


void GameMenuState::setPushDeferredFn(pushDeferred_t fn)
{
    this->pushDeferred = fn;

    resumeBtn = new Button(window->getSize().x * 0.5, window->getSize().y * 0.35 , 200, conf::btnTextHeight);
    resumeBtn->setWindow(*window);
    resumeBtn->setText("Resume", conf::defaultFontName, conf::btnDefaultColor, conf::btnTextHeight);
    
    exitBtn = new Button(window->getSize().x * 0.5, window->getSize().y * 0.5 , 300, conf::btnTextHeight);
    exitBtn->setWindow(*window);
    exitBtn->setText("Exit game", conf::defaultFontName, conf::btnDefaultColor, conf::btnTextHeight);
    
    resumeBtn->submit( std::bind(pushDeferred, [](StateStack* stateStack) {
        if(typeid(stateStack->top()) == typeid(GameState*)) return ;    
        stateStack->pop();
        //stateStack->pop();
        //stateStack->push(IAppStatePtr(new GameState));
    }) );
    exitBtn->submit( std::bind(pushDeferred, [&](StateStack*) {
        if(window->isOpen()) window->close();
    }));
}
