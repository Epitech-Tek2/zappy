//
// Created by Patrick Eiermann on 25/05/2021.
//

#ifndef B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_INTRO_HPP
#define B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_INTRO_HPP

#include "../../Scene.hpp"
#include "../menu/Menu.hpp"
#include "../gameSolo/GameSolo.hpp"
#include "../gameMulti/GameMulti.hpp"

class Intro : public Scene {
public:
    explicit Intro(sf::RenderWindow *window);

    void init() final override;

    void display() final override;

    Scene_E update(Menu *menu, GameSolo *gameSolo, GameMulti *gameMulti);

    Scene_E update() final override;

private:
    sf::RenderWindow *_window;

    void setMessage(const std::string &mess);

    sf::Sprite _title;
    sf::Font font;
    sf::Texture _titleTexture;
    sf::Text _mess;
};

extern void setText(sf::Text *text, sf::Vector2f _pour);

#endif //B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_INTRO_HPP
