#ifndef MAINMENUSTATE_ES88MA91
#define MAINMENUSTATE_ES88MA91

#include <functional>

#include <SFML/Graphics.hpp>


#include "States/IAppState.hpp"
#include "Common/Deferred.hpp"

#include "Common/Button.hpp"
#include "States/GameState.hpp"

typedef sf::Event event_t;


class MainMenuState : public IAppState  {
private:

    Button * exitBtn;
    Button * startBtn;
    sf::Sprite bgSprite;
    sf::Texture bgTexture;
public:
    MainMenuState();
    virtual ~MainMenuState();

    virtual void draw();
    virtual void handleEvents(const event_t&);
    virtual void update(const float&);
    //void setWindow(window_t & window);

    void load(window_t &window, StateStack& st, std::function<void(IDeferred*)>& fn);
};



#endif /* end of include guard: MAINMENUSTATE_ES88MA91 */
