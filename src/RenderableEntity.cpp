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

void RenderableEntity::setPosition(const sf::Vector2f& position) {

    m_position = position;
}

void RenderableEntity::wrapInWindow(sf::RenderWindow* window) {
    auto dimensions = window->getSize();

    if (m_position.x < 0){
        m_position.x = dimensions.x;
    }

    if ( m_position.x > dimensions.x )
    {
        m_position.x = 0;
    }

    if ( m_position.y < 0 )
    {
        m_position.y = dimensions.y;
    }

    if ( m_position.y > dimensions.y )
    {
        m_position.y = 0;
    }
}

