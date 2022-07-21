//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include "../include/Player.h"


void Player::render(sf::RenderWindow* window) {
    window->draw(this->m_sprite);
}
