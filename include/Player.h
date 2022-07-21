//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "RenderableEntity.h"

class Player : public RenderableEntity{
  public:
    void render(sf::RenderWindow* window) override;

};

#endif //_PLAYER_H_
