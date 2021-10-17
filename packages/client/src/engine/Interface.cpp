#include "../include/engine/Interface.hpp"
#include "../include/Global.hpp"
#include <SFML/OpenGL.hpp>

Interface::Interface()
    : _screenX(sf::VideoMode::getDesktopMode().width),
      _screenY(sf::VideoMode::getDesktopMode().height) {
    _window.create(sf::VideoMode(_screenX, _screenY), "ZAPPY",
                   sf::Style::Default, sf::ContextSettings(24, 0, 2));
    _window.setFramerateLimit(60);
    _window.setVerticalSyncEnabled(true);

    // Configure OpenGL features.
    _window.resetGLStates();  // Enables {VERTEX,TEXTURE_COORD,COLOR}_ARRAY, TEXTURE_2D. Disables LIGHTING,CULL_FACE.
    glDisableClientState(GL_NORMAL_ARRAY); // Disable normals, not used.
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.f);

    this->_clock = new sf::Clock();
    // Scene initialisation
    this->_intro = new Intro(&_window);
    this->_menu = new Menu(&_window);
    this->_gameSolo = new GameSolo(&_window);
    this->_gameMulti = new GameMulti(&_window);

    //if (DEBUG_CONTROLLER)
    std::cout << "[Client] Start initialisation of the interface" << std::endl;
    //if (DEBUG_CONTROLLER)
    std::cout << "[Client] Initialisation finished" << std::endl;
}

void Interface::init() {

}

Interface::~Interface() {
    // #todo correct crash of delete menu

    //if (this->_menu != nullptr)
    //    delete this->_menu;
    //if (this->_gameSolo != nullptr)
    //    delete this->_gameSolo;
    //if (this->_gameMulti != nullptr)
    //    delete this->_gameMulti;
    if (this->_intro != nullptr)
        delete this->_menu;
    if (this->_clock != nullptr)
        delete this->_clock;
}

void Interface::clearScreen() {
    if (scene == Scene_E::INTRO)
        _window.clear(sf::Color::White);
    else
        _window.clear(sf::Color::Black);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Interface::refreshScreen() {
    _window.display();
}

Event Interface::handleEvent() {
    while (_window.pollEvent(_event)) {
        switch (_event.type) {
            case sf::Event::Closed:
                _window.close();
                return (Event::quit);
            case sf::Event::KeyPressed:
                switch (_event.key.code) {
                    return (Event::quit);
                    case sf::Keyboard::Enter:
                        return Event::enter;
                }
        }
    }
    return Event::unknown;
}

bool Interface::isOn() const {
    if (scene == Scene_E::QUIT)
        return false;
    return true;
}


void Interface::update() {
    sf::Time time = _clock->getElapsedTime();
    float seconds = time.asSeconds();

    if (seconds >= 0.01) {
        switch (scene) {
            case Scene_E::INTRO:
                scene = _intro->update(_menu, _gameSolo, _gameMulti);
                break;
            case Scene_E::MENU:
                scene = _menu->update();
                break;
            case Scene_E::GAME_MULTI:
                scene = _gameMulti->update();
                break;
            case Scene_E::GAME_SOLO:
                scene = _gameSolo->update();
                break;
        }
        _clock->restart();
    }
}

void Interface::render() {
    if (scene == Scene_E::GAME_SOLO)
        _gameSolo->displayEffect();

    _window.pushGLStates();
    switch (scene) {
        case Scene_E::INTRO:
            _intro->display();
            break;
        case Scene_E::MENU:
            _menu->display();
            break;
        case Scene_E::GAME_MULTI:
            _gameMulti->display();
            break;
        case Scene_E::GAME_SOLO:
            _gameSolo->display();
            break;
    }
    _window.popGLStates();
}