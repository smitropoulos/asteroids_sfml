//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include "Player.h"

void Player::load(const sf::Texture *texture) {

    RenderableEntity::load(texture);
    m_sprite.setPosition(100.f, 100.f);
}
