#include "States/GameOverState.hpp"

GameOverState::GameOverState()
{
}

GameOverState::~GameOverState()
{
    delete restartBtn;
    delete exitBtn;
    delete mainMenuBtn;
}  

void GameOverState::handleEvents(const event_t& event)
{
    restartBtn->handleEvents(event);
    exitBtn->handleEvents(event);
    mainMenuBtn->handleEvents(event);
}

void GameOverState::update(const float& dt)
{
}

void GameOverState::draw()
{
    window->draw(bgSprite);
    restartBtn->draw();
    exitBtn->draw();
    mainMenuBtn->draw();
    window->draw(gameOverText);
}

void GameOverState::setPushDeferredFn(pushDeferred_t fn)
{
    this->pushDeferred = fn;

    Vec2<float> logoPos(window->getSize().x * 0.38, window->getSize().y * 0.1);
    gameOverText.setFont(conf::defaultFont);
    gameOverText.setString("GAME OVER");
    gameOverText.setColor(sf::Color::Red);
    gameOverText.setOrigin(200, conf::btnTextHeight / 2);
    gameOverText.setPosition(logoPos.x, logoPos.y);
    gameOverText.setCharacterSize(conf::defaultTextHeight * 1.5);

    restartBtn = new Button(window->getSize().x * 0.5, window->getSize().y * 0.35 , 200, conf::btnTextHeight);
    restartBtn->setWindow(*window);
    restartBtn->setText("Restart", conf::defaultFontName, conf::btnDefaultColor, conf::btnTextHeight);
    
    mainMenuBtn = new Button(window->getSize().x * 0.5, window->getSize().y * 0.5 , 300, conf::btnTextHeight);
    mainMenuBtn->setWindow(*window);
    mainMenuBtn->setText("Main menu", conf::defaultFontName, conf::btnDefaultColor, conf::btnTextHeight);

    exitBtn = new Button(window->getSize().x * 0.5, window->getSize().y * 0.75 , 300, conf::btnTextHeight);
    exitBtn->setWindow(*window);
    exitBtn->setText("Exit game", conf::defaultFontName, conf::btnDefaultColor, conf::btnTextHeight);
    
    restartBtn->submit( std::bind(pushDeferred, [](StateStack* stateStack) {
        if(typeid(stateStack->top()) == typeid(GameState*)) return ;    
        stateStack->pop();
        stateStack->pop();
        stateStack->push(IAppStatePtr(new GameState));
    }));
    mainMenuBtn->submit( std::bind(pushDeferred, [](StateStack* stateStack) {
        if(typeid(stateStack->top()) == typeid(GameState*)) return ;    
        stateStack->pop();
        stateStack->pop();
        stateStack->push(IAppStatePtr(new MainMenuState));
    }));
    exitBtn->submit(std::bind(pushDeferred, [&](StateStack*) {
        if(window->isOpen()) window->close();
    }));
}