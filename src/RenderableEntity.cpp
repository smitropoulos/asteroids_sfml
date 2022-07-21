//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include "RenderableEntity.h"


RenderableEntity::~RenderableEntity() {
    delete m_texture;
}

RenderableEntity::RenderableEntity() {
    m_texture = new sf::Texture;
}

void RenderableEntity::setPosition(const sf::Vector2i& position) {

    m_position = position;
}
