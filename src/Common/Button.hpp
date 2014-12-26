#ifndef BUTTON_I0GSPT6W
#define BUTTON_I0GSPT6W

#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Common/BasicTypes.hpp"
#include "Common/Vec2.hpp"

class Button {
private:
    texture_t texture;
    sprite_t  sprite;
    std::function<void()> sbmt;
    window_t * window;
    sf::Font font;
    sf::Text text;
    sf::Color textColor;

    Vec2<float> pos;
    float height;
    float width;

public:
    Button(float x, float y, float width, float height);
    virtual ~Button();


    void handleEvents(const event_t&);
    void update(const float& dt);
    void submit(std::function<void()> def);
    void draw();

    void setWindow(window_t & window);
    void setText(std::string text, std::string fontName, sf::Color color, int charSize);
    void setTexture(std::string textureName);
    bool isIntersect(const float& x, const float& y);

};


#endif /* end of include guard: BUTTON_I0GSPT6W */
