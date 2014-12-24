#ifndef MAINMENUSTATE_ES88MA91
#define MAINMENUSTATE_ES88MA91

#include <functional>

#include <SFML/Graphics.hpp>


#include "Common/Interfaces/IAppState.hpp"
#include "Common/Deferred.hpp"


#include "Common/Button.hpp"
#include "States/MainMenuState.hpp"
#include "States/GameState.hpp"
#include "States/MainMenuState.hpp"

typedef sf::Event event_t;

class MainMenuState;

class GameMenuState : public IAppState  {
private:
    Button * exitBtn;
    Button * resumeBtn;
    sf::Sprite bgSprite;
    sf::Texture bgTexture;

public:
    GameMenuState();
    virtual ~GameMenuState();

    virtual void draw();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    void setWindow(window_t & window);

    void load(window_t &window, StateStack& st, std::function<void(IDeferred*)>& fn);
};



#endif /* end of include guard: MAINMENUSTATE_ES88MA91 */
