//
// Created by Patrick Eiermann on 25/05/2021.
//

#include "Button.hpp"

extern void setImage(sf::Sprite *sprite, sf::Vector2f _pour, sf::Vector2u _screen);

Button::Button(sf::Vector2f pos, const char *path, sf::Vector2f scale, sf::Vector2u screen) :
    _posX(pos.x), _posY(pos.y), _scaleX(scale.x), _scaleY(scale.y), _screen(screen)
{
    if (!tmp.loadFromFile(path))
        std::cout << "Fail to load Texture" << std::endl;
    _button.setTexture(tmp);

    _button.setScale(_scaleX, _scaleY);
    setImage(&_button, sf::Vector2f(_posX, _posY), _screen);
}

static int getSizeX(sf::Sprite sprite)
{
    return (sprite.getLocalBounds().width * sprite.getScale().x);
}

static int getSizeY(sf::Sprite sprite)
{
    return (sprite.getLocalBounds().height * sprite.getScale().y);
}

bool Button::isClicked(sf::Vector2i mousePos)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        if (mousePos.x > _button.getPosition().x && mousePos.x < _button.getPosition().x + getSizeX(_button))
            if (mousePos.y > _button.getPosition().y && mousePos.y < _button.getPosition().y + getSizeY(_button))
                return (true);
    return (false);
}

sf::Sprite Button::getSprite() const
{
    return _button;
}

void Button::setText(std::string const &text, const int size)
{
    float posX = 0;
    float posY = 0;

    if (!_font.loadFromFile("./assets/font/Minecraft.ttf"))
        std::cout << "[Client][Button] Error loading font" << std::endl;
    _text.setFont(_font);
    _text.setString(text);
    _text.setCharacterSize(size);
    _text.setFillColor(sf::Color::White);
    sf::Vector2f scale = _button.getScale();
    posX = _button.getPosition().x + ((_button.getLocalBounds().width * scale.x / 2) - (_text.getLocalBounds().width / 2));
    posY = _button.getPosition().y + ((_button.getLocalBounds().height * scale.y / 2) - (_text.getLocalBounds().height / 2));;
    _text.setPosition(sf::Vector2f(posX, posY));
}

void Button::display(sf::RenderWindow *win)
{
    win->draw(_button);
    win->draw(_text);
}