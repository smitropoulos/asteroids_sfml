//
// Created by Stefanos Mitropoulos on 21/7/22.
//

#include "PlayerEventHandler.h"
#include "EntitiesRepository.h"


void PlayerEventHandler::handleEvent(sf::Event event) {
}

void PlayerEventHandler::handleKeyboardEvent(sf::Event event, bool isActive) {

    if(!isActive)
    {
        m_movement = MovementType::NONE;
        return;
    }

    if ( event.key.code == sf::Keyboard::W )
    {
        m_movement = MovementType::UP;
    }
    else if ( event.key.code == sf::Keyboard::S )
    {
        m_movement = MovementType::DOWN;
    }
    else if ( event.key.code == sf::Keyboard::A )
    {
        m_movement = MovementType::LEFT;
    }
    else if ( event.key.code == sf::Keyboard::D )
    {
        m_movement = MovementType::RIGHT;
    }
}

MovementType PlayerEventHandler::movement() const {

    return m_movement;
}
