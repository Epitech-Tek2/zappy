/*
** EPITECH PROJECT, 2021
** Scene.hpp
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/Global.hpp"
#include <SFML/OpenGL.hpp>

class Scene {
public:
    virtual ~Scene() = default;

    virtual void init() = 0;

    virtual void display() = 0;

    virtual Scene_E update() = 0;

};

#endif /* !SCENE_HPP_ */
