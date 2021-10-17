//
// Created by Patrick Eiermann on 26/05/2021.
//

#ifndef B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_GAMESOLO_HPP
#define B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_GAMESOLO_HPP

#include "../../Scene.hpp"
#include <cmath>
#include <vector>
#include <array>

class GameSolo : public Scene {
public:
    explicit GameSolo(sf::RenderWindow *window);

    void init() final override;

    void display() final override;

    Scene_E update() final override;

    void displayEffect();

private:
    sf::RenderWindow *_window;
    sf::Texture _tx[7];
    std::vector <GLfloat> tri;
    std::map<int, bool> keys;
    float rx = 0, ry = 1, rz = -.1, mx = 0, my = 0, mz = -2.5, lx = 3.86, ly = -0.29, lz = 15.9, aa = 0.92, ab = -0.18, ac = -0.35, ad = 0.07, fog = 4;
    GLfloat tform[16]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
                      1}; // Initialize default transformation matrix.
    GLfloat far = 50.f;
    sf::Texture InventoryTexture;
    sf::Texture CrossHairTexture;
    sf::Sprite _inventory;
    sf::Sprite _crossHair;
};

extern void
setImage(sf::Sprite *sprite, sf::Vector2f _pour, sf::Vector2u _screen);

#endif //B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_GAMESOLO_HPP
