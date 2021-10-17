/*
** EPITECH PROJECT, 2021
** setImage.cpp
** File description:
** setImage
*/

#include <SFML/Graphics.hpp>

void setImage(sf::Sprite *sprite, sf::Vector2f _pour, sf::Vector2u _screen)
{
    int _screenX = _screen.x;
    int _screenY = _screen.y;
    sf::Vector2f scale = sprite->getScale();
    float posX = 0;
    float posY = 0;

    if (_pour.x != 0)
        posX = (_screenX * _pour.x) / 100;
    if (_pour.y != 0)
        posY = (_screenY * _pour.y) / 100;
    posX -= (sprite->getLocalBounds().width * scale.x) / 2;
    posY -= (sprite->getLocalBounds().height * scale.y) / 2;
    sprite->setPosition(sf::Vector2f(posX, posY));
}