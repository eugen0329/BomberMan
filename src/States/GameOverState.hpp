#ifndef GAMEOVERSTATE_ES88MA91
#define GAMEOVERSTATE_ES88MA91

#include <functional>

#include <SFML/Graphics.hpp>

#include "Common/BasicTypes.hpp"
#include "GlobalConf.hpp"

#include "States/IAppState.hpp"
#include "Common/Button.hpp"

#include "States/MainMenuState.hpp"
#include "States/GameState.hpp"
#include "States/MainMenuState.hpp"



class MainMenuState;

class GameOverState : public IAppState  {
private:
    Button * exitBtn;
    Button * restartBtn;
    sprite_t bgSprite;
    texture_t bgTexture;
    sf::Text gameOverText;

public:
    GameOverState();
    virtual ~GameOverState();

    virtual void draw();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void setPushDeferredFn(pushDeferred_t);
};

#endif /* end of include guard: GAMEOVERSTATE_ES88MA91 */
