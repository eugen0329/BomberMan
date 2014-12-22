#include "Game/Menu/GameMenuState.hpp"


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
    if(event.type == sf::Event::Closed) { 
        window->close();
    }
    resumeBtn->handleEvents(event);
    exitBtn->handleEvents(event);
}

void GameMenuState::update(const float& dt)
{
}

void GameMenuState::draw()
{
    //window->clear(sf::Color::White);
    window->draw(bgSprite);
    resumeBtn->draw();
    exitBtn->draw();

}


void GameMenuState::load(window_t &window, StateStack& st, std::function<void(IDeferred*)>& fn)
{
    this->window = &window;
    pushDeferred = fn;
    stateStack = &st;

    //bgTexture.loadFromFile("./res/space.png");
    //bgSprite.setTexture(bgTexture);


    // loading buttons
    int textHeight = 80;
    resumeBtn = new Button(window.getSize().x * 0.5, window.getSize().y * 0.35 , 200, textHeight);
    resumeBtn->setWindow(window);
    resumeBtn->setText("Resume", "./res/Arcade.ttf", sf::Color(84, 84, 84), textHeight);
    
    exitBtn = new Button(window.getSize().x * 0.5, window.getSize().y * 0.5 , 300, textHeight);
    exitBtn->setWindow(window);
    exitBtn->setText("Exit game", "./res/Arcade.ttf", sf::Color(84, 84, 84), textHeight);
    

    exitBtn->submit( std::bind(pushDeferred, new Deferred<void>([&]() {
        window.close();
    })) );

    resumeBtn->submit( std::bind(pushDeferred, new Deferred<void>([&]() {
        if(typeid(stateStack->top()) == typeid(GameState*)) return ;    // if state already changed
        stateStack->pop();
        //stateStack->push(new GameState);
    })) );
}