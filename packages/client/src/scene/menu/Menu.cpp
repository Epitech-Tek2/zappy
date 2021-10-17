/*
** EPITECH PROJECT, 2021
** Menu.cpp
** File description:
** Menu
*/

#include "../../../include/scene/menu/Menu.hpp"

Menu::Menu(sf::RenderWindow *window)
    : _window(window),
      _backgroundDirectory("./assets/sprite/cinematic/background/") {
}

Menu::~Menu() {
    if (_soloButton != nullptr)
        delete _soloButton;
    if (_multiButton != nullptr)
        delete _multiButton;
    if (_optionsButton != nullptr)
        delete _optionsButton;
    if (_quitButton != nullptr)
        delete _quitButton;
}

void Menu::init() {
    std::vector <std::string> backgroundList;
    sf::Texture texture;

    _backgroundDirectory.sort();
    backgroundList = _backgroundDirectory.getList();
    for (std::string const &_backgroundFile : backgroundList) {
        if (!texture.loadFromFile(_backgroundFile))
            std::cout << "Error texture" << std::endl;
        _background.push_back(texture);
    }
    // setSprite Image
    _backgroundSprite.setScale(2.0, 2.0);

    // set title
    if (!_titleTexture.loadFromFile("./assets/sprite/images/ZAPPY.png"))
        std::cout << "Fail to load Menu title" << std::endl;
    _title.setTexture(_titleTexture);

    _title.setScale(2.3, 2.0);
    setImage(&_title, sf::Vector2f{50, 15}, _window->getSize());

    if (!_sound.openFromFile("./assets/sound/C418.ogg"))
        std::cout << "Fail to load music" << std::endl;
    _sound.setVolume(50);
    _sound.setLoop(true);
    _sound.play();

    this->_soloButton =
        new Button(sf::Vector2f{50, 40},
                   "./assets/sprite/images/button/Large.png",
                   sf::Vector2f{1.5, 1.5}, _window->getSize());
    _soloButton->setText("Singleplayer", 45);
    this->_multiButton =
        new Button(sf::Vector2f{50, 47},
                   "./assets/sprite/images/button/Large.png",
                   sf::Vector2f{1.5, 1.5}, _window->getSize());
    _multiButton->setText("Multiplayer", 45);
    this->_optionsButton =
        new Button(sf::Vector2f{50, 54},
                   "./assets/sprite/images/button/Large.png",
                   sf::Vector2f{1.5, 1.5}, _window->getSize());
    _optionsButton->setText("Options...", 45);
    this->_quitButton =
        new Button(sf::Vector2f{50, 61},
                   "./assets/sprite/images/button/Large.png",
                   sf::Vector2f{1.5, 1.5}, _window->getSize());
    _quitButton->setText("Quit Game", 45);
}

void Menu::backgroundUpdate() {
    static unsigned long pos = 0;
    static bool rev = true;

    if (rev) {
        if (pos == _background.size())
            rev = false;
        else pos++;
    } else {
        if (pos == 0)
            rev = true;
        else pos--;
    }
    if (pos < _background.size() && pos >= 0)
        _backgroundSprite.setTexture(_background.at(pos));
}

Scene_E Menu::update() {
    this->backgroundUpdate();
    if (_soloButton->isClicked(sf::Mouse::getPosition(*_window))) {
        return Scene_E::GAME_SOLO;
    }
    if (_multiButton->isClicked(sf::Mouse::getPosition(*_window))) {
        return Scene_E::GAME_MULTI;
    }
    if (_quitButton->isClicked(sf::Mouse::getPosition(*_window))) {
        return Scene_E::QUIT;
    }
    return Scene_E::MENU;
}

void Menu::display() {
    _window->draw(this->_backgroundSprite);
    _window->draw(this->_title);
    _soloButton->display(_window);
    _multiButton->display(_window);
    _optionsButton->display(_window);
    _quitButton->display(_window);
}