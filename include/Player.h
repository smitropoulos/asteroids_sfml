//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "RenderableEntity.h"
#include "PlayerEventHandler.h"


class Player : public RenderableEntity{
  protected:
    PlayerEventHandler* m_playerEventHandler;
  public:
    void setPlayerEventHandler(PlayerEventHandler *playerEventHandler);
    void load(const sf::Texture *texture) override;
    void update() override;
    void moveForward();
    void moveBackward();
    void stopMovement();
    void strafeClockwise();
};

#endif //_PLAYER_H_
