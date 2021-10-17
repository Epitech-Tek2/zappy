/*
** EPITECH PROJECT, 2021
** Interface.hpp
** File description:
** Interface
*/

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else

#include <GL/glut.h>

#endif

#include "../scene/intro/Intro.hpp"
#include "../scene/gameSolo/GameSolo.hpp"
#include "../scene/gameMulti/GameMulti.hpp"
#include "../Event.hpp"
#include <iostream>

class Interface {
public:
    Interface();

    ~Interface();

    void init();

    void clearScreen();

    Event handleEvent();

    void update();

    void render();

    void refreshScreen();

    bool isOn() const;

private:
    sf::RenderWindow _window;
    sf::Event _event;
    sf::Clock *_clock = nullptr;

    unsigned int _screenX = 0;
    unsigned int _screenY = 0;

    //Scene
    Scene_E scene = Scene_E::INTRO;
    Intro *_intro = nullptr;
    Menu *_menu = nullptr;
    GameSolo *_gameSolo = nullptr;
    GameMulti *_gameMulti = nullptr;

    sf::Texture _tx[7];
    std::vector <GLfloat> tri;
    std::map<int, bool> keys;
    GLfloat far = 50.f;
};

#endif /* !INTERFACE_HPP_ */
