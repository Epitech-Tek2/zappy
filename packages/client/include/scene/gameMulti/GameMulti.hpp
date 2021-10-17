//
// Created by Patrick Eiermann on 26/05/2021.
//

#ifndef B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_GAMEMULTI_HPP
#define B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_GAMEMULTI_HPP

#include "../../Scene.hpp"

class GameMulti : public Scene {
public:
    explicit GameMulti(sf::RenderWindow *window);

    void init() final override;

    void display() final override;

    Scene_E update() final override;

private:
    sf::RenderWindow *_window;
};


#endif //B_YEP_410_STG_4_1_ZAPPY_PATRICK_EIERMANN_GAMEMULTI_HPP
