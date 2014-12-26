#include "States/MainMenuState.hpp"

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
    window->draw(logo);
    startBtn->draw();
    exitBtn->draw();
}

void MainMenuState::setPushDeferredFn(pushDeferred_t fn)
{
    pushDeferred = fn;

    bgTexture.loadFromFile("./res/space.png");
    bgSprite.setTexture(bgTexture);

    Vec2<float> logoPos(window->getSize().x * 0.38, window->getSize().y * 0.1);
    logo.setFont(conf::defaultFont);
    logo.setString(conf::logoText);
    logo.setColor(conf::defaultColor);
    logo.setOrigin(200, conf::btnTextHeight / 2);
    logo.setPosition(logoPos.x, logoPos.y);
    logo.setCharacterSize(conf::defaultTextHeight * 1.5);

    startBtn = new Button(window->getSize().x * 0.5, window->getSize().y * 0.55 , 200, conf::btnTextHeight);
    startBtn->setWindow(*window);
    startBtn->setText("Start", conf::defaultFontName, conf::btnDefaultColor, conf::btnTextHeight);
    
    exitBtn = new Button(window->getSize().x * 0.5, window->getSize().y * 0.80 , 150, conf::btnTextHeight);
    exitBtn->setWindow(*window);
    exitBtn->setText("Exit", conf::defaultFontName, conf::btnDefaultColor, conf::btnTextHeight);

    startBtn->submit( std::bind(pushDeferred, [](StateStack* st) {
        if(typeid(st->top()) == typeid(GameState*)) return ;    // if state already changed
        st->pop();
        st->push(IAppStatePtr(new GameState));
        
    }));

    exitBtn->submit(std::bind(pushDeferred, [&](StateStack*) {
        if(window->isOpen()) window->close();

    }));
}