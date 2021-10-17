/*
** EPITECH PROJECT, 2021
** Menu.hpp
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "../../../libs/client/GetFileDirectory/GetFileDirectory.hpp"
#include "../../../libs/client/Button/Button.hpp"
#include "../../Scene.hpp"

class Menu : public Scene {
public:
    Menu(sf::RenderWindow *window);

    ~Menu();

    void init() final override;

    void display() final override;

    Scene_E update() final override;

private:
    sf::RenderWindow *_window;
    GetFileDirectory _backgroundDirectory;

    void backgroundUpdate();

    std::vector <sf::Texture> _background;
    sf::Sprite _backgroundSprite;
    sf::Sprite _title;
    sf::Music _sound;
    sf::Texture _titleTexture;
    Button *_soloButton = nullptr;
    Button *_multiButton = nullptr;
    Button *_optionsButton = nullptr;
    Button *_quitButton = nullptr;
};

extern void
setImage(sf::Sprite *sprite, sf::Vector2f _pour, sf::Vector2u _screen);

#endif /* !MENU_HPP_ */
