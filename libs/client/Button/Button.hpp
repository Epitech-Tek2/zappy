//
// Created by Patrick Eiermann on 25/05/2021.
//

#ifndef B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_CREATEBUTTON_HPP
#define B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_CREATEBUTTON_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
    Button(sf::Vector2f pos, const char *path, sf::Vector2f scale, sf::Vector2u screen);
    ~Button() = default;
    sf::Sprite getSprite() const;
    bool isClicked(sf::Vector2i mousePos);
    void setText(std::string const &text, const int size);
    void display(sf::RenderWindow *win);
private:
    sf::Texture tmp;
    sf::Sprite _button;
    sf::Text _text;
    sf::Font _font;
    unsigned int _posX = 0;
    unsigned int _posY = 0;
    float _scaleX = 0;
    float _scaleY = 0;
    sf::Vector2u _screen;
};


#endif //B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_CREATEBUTTON_HPP
