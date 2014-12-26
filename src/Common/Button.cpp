#include "Common/Button.hpp"


Button::Button(float x, float y, float width, float height)
{
    this->pos.setComponents(x, y);
    this->width = width;
    this->height = height;
}

Button::~Button()
{
}

void Button::setTexture(std::string textureName)
{
    texture.loadFromFile(textureName);
    sprite.setTexture(texture);
    sprite.setPosition(pos.x, pos.y);
}

void Button::setWindow(window_t & window)
{
    this->window = &window;
}

void Button::handleEvents(const event_t& event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if ( event.mouseButton.button == sf::Mouse::Left && isIntersect(event.mouseButton.x, event.mouseButton.y) ) {
            sbmt();
        }
    }
    if (event.type == sf::Event::MouseMoved) {
        if ( isIntersect(event.mouseMove.x, event.mouseMove.y) ) {
            this->text.setColor(sf::Color::White);
        } else {
            this->text.setColor(textColor);
        }
    }
}

void Button::update(const float& dt)
{
}

void Button::draw()
{
    window->draw(text);
    window->draw(sprite);
}

void Button::setText(std::string text, std::string fontName, sf::Color color,int charSize)
{
    if (!this->font.loadFromFile(fontName)) 
        throw std::invalid_argument(std::string("ERROR: wrong font ") + fontName ); 
    this->textColor = color;
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setColor(textColor);
    this->text.setOrigin(width / 2, height / 2);
    this->text.setPosition(pos.x, pos.y);
    this->text.setCharacterSize(charSize);
}

bool Button::isIntersect(const float& x, const float& y)
{
    return pos.x - width / 2  < x && x < pos.x + width / 2 && 
           pos.y - height / 4 < y && y < pos.y + height / 3 ;
}

void Button::submit(std::function<void()> def)
{
    sbmt = def;
}