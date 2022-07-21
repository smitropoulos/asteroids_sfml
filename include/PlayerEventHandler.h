//
// Created by Stefanos Mitropoulos on 21/7/22.
//

#ifndef _PLAYEREVENTHANDLER_H_
#define _PLAYEREVENTHANDLER_H_

#include "EventHandler.h"
#include "MovementType.h"


class PlayerEventHandler : public EventHandler {
  private:
    MovementType m_movement{MovementType::NONE};
  public:
    void handleEvent(sf::Event event) override;
    void handleKeyboardEvent(sf::Event event, bool isActive);
    [[nodiscard]] MovementType movement() const;
};

#endif //_PLAYEREVENTHANDLER_H_
