//
// Created by Stefanos Mitropoulos on 21/7/22.
//

#include "Rock.h"

void Rock::load(const sf::Texture *texture) {

    RenderableEntity::load(texture);
    m_sprite.setPosition(200.f, 200.f);
}
