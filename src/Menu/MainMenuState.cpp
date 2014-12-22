#include "Menu/MainMenuState.hpp"


MainMenuState::MainMenuState()
{

}

MainMenuState::~MainMenuState()
{
    delete startBtn;
    delete exitBtn;
}  

void MainMenuState::handleEvents(const event_t& event)
{
    if(event.type == sf::Event::Closed) { 
        window->close();
    }
    startBtn->handleEvents(event);
    exitBtn->handleEvents(event);
}

void MainMenuState::update(const float& dt)
{
}

void MainMenuState::draw()
{
    window->clear(sf::Color::White);
    window->draw(bgSprite);
    startBtn->draw();
    exitBtn->draw();

}


void MainMenuState::load(window_t &window, StateStack& st, std::function<void(IDeferred*)>& fn)
{
    this->window = &window;
    pushDeferred = fn;
    stateStack = &st;

    bgTexture.loadFromFile("./res/space.png");
    bgSprite.setTexture(bgTexture);

    int textHeight = 80;
    startBtn = new Button(window.getSize().x * 0.5, window.getSize().y * 0.5 , 200, textHeight);
    startBtn->setWindow(window);
    startBtn->setText("Start", "./res/Arcade.ttf", sf::Color(84, 84, 84), textHeight);
    startBtn->submit( std::bind([&](){ pushDeferred(new Deferred<void>(changeToGame, stateStack)); }) );


    exitBtn = new Button(window.getSize().x * 0.5, window.getSize().y * 0.75 , 150, textHeight);
    exitBtn->setWindow(window);
    exitBtn->setText("Exit", "./res/Arcade.ttf", sf::Color(84, 84, 84), textHeight);
    //exitBtn->submit(new Deferred<void>(changeToGame, stateStack));

}