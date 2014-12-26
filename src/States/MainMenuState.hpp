#ifndef MAINMENUSTATE_ES88MA91
#define MAINMENUSTATE_ES88MA91

#include <functional>

#include <SFML/Graphics.hpp>

#include "Common/BasicTypes.hpp"
#include "States/IAppState.hpp"
#include "Common/Button.hpp"
#include "States/GameState.hpp"

typedef sf::Event event_t;


class MainMenuState : public IAppState  {
private:
    Button * exitBtn;
    Button * startBtn;
    sprite_t bgSprite;
    texture_t bgTexture;
    sf::Text logo;
public:
    MainMenuState();
    virtual ~MainMenuState();

    virtual void draw();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);

    virtual void setPushDeferredFn(pushDeferred_t fn);
};



#endif /* end of include guard: MAINMENUSTATE_ES88MA91 */
