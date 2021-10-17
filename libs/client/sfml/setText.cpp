/*
** EPITECH PROJECT, 2021
** setText.cpp
** File description:
** setText
*/

#include <SFML/Graphics.hpp>

void setText(sf::Text *text, sf::Vector2f _pour)
{
    int _screenX = sf::VideoMode::getDesktopMode().width;
    int _screenY = sf::VideoMode::getDesktopMode().height;
    sf::Vector2f scale = text->getScale();
    float posX = 0;
    float posY = 0;

    if (_pour.x != 0)
        posX = (_screenX * _pour.x) / 100;
    if (_pour.y != 0)
        posY = (_screenY * _pour.y) / 100;
    posX -= (text->getLocalBounds().width * scale.x) / 2;
    posY -= (text->getLocalBounds().height * scale.y) / 2;
    text->setPosition(sf::Vector2f(posX, posY));
}