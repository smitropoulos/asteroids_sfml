//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include "Player.h"


void Player::load(const sf::Texture *texture) {

    RenderableEntity::load(texture);
    m_position.x = 100.0f;
    m_position.y = 100.0f;
    m_sprite.setPosition(m_position.x, m_position.y);
}

void Player::moveForward() {

    m_sprite.setPosition(m_position.x, m_position.y++);
}

void Player::moveBackward() {

    m_sprite.setPosition(m_position.x, m_position.y--);
}

void Player::update() {

    //update movement
    auto movement = m_playerEventHandler->movement();
    switch ( movement )
    {
        case MovementType::NONE:
        {
            stopMovement();
            break;
        }
        case MovementType::UP:
        {
            moveForward();
            break;
        }
        case MovementType::DOWN:
        {
            moveBackward();
            break;
        }
        case MovementType::LEFT:
        {
            strafeClockwise();
            break;
        }
        case MovementType::RIGHT:
        {
            strafeClockwise();
            break;
        }
    }
}

void Player::setPlayerEventHandler(PlayerEventHandler *playerEventHandler) {

    m_playerEventHandler = playerEventHandler;
}

void Player::stopMovement() {

    m_sprite.setPosition(m_position.x, m_position.y);
}

void Player::strafeClockwise() {

    m_angle += 1;
    m_sprite.setRotation(m_angle);
}

