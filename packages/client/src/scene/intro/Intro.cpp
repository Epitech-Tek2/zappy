//
// Created by Patrick Eiermann on 25/05/2021.
//

#include "../../../include/scene/intro/Intro.hpp"

Intro::Intro(sf::RenderWindow *window) : _window(window) {
    if (!_titleTexture.loadFromFile("./assets/sprite/images/ZAPPY.png"))
        std::cout << "Fail to load Menu title" << std::endl;
    _title.setTexture(_titleTexture);

    _title.setScale(2.3, 2.0);
    setImage(&_title, sf::Vector2f{50, 20}, _window->getSize());

    if (!font.loadFromFile("./assets/font/Minecraft.ttf")) {
        std::cout << "Error font" << std::endl;
    }
    _mess.setFont(font); // font is a sf::Font
    _mess.setCharacterSize(70); // in pixels, not points!
    _mess.setFillColor(sf::Color::Black);
    setMessage("Loading ...");
}

void Intro::setMessage(const std::string &mess) {
    this->_mess.setString(mess.c_str());
    setText(&this->_mess, sf::Vector2f{50, 60});
}

void Intro::init() {

}

Scene_E Intro::update(Menu *menu, GameSolo *gameSolo, GameMulti *gameMulti) {
    static int count = 0;

    if (count >= 4)
        return Scene_E::MENU;
    switch (count) {
        case 1:
            setMessage("[Load] Menu assets");
            menu->init();
            break;
        case 2:
            setMessage("[Load] Multiplayer assets");
            gameMulti->init();
            break;
        case 3:
            setMessage("[Load] Solo assets");
            gameSolo->init();
            break;
        default:
            break;
    }
    count++;
    return Scene_E::INTRO;
}

Scene_E Intro::update() {
    return Scene_E::INTRO;
}

void Intro::display() {
    _window->draw(this->_title);
    _window->draw(_mess);
}