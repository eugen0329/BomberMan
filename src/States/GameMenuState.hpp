#ifndef MAINMENUSTATE_ES88MA91
#define MAINMENUSTATE_ES88MA91

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

class GameMenuState : public IAppState  {
private:
    Button * exitBtn;
    Button * resumeBtn;
    sprite_t bgSprite;
    texture_t bgTexture;

public:
    GameMenuState();
    virtual ~GameMenuState();

    virtual void draw();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    virtual void setPushDeferredFn(pushDeferred_t);
};

#endif /* end of include guard: MAINMENUSTATE_ES88MA91 */
