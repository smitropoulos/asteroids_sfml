//
// Created by Stefanos Mitropoulos on 21/7/22.
//

#ifndef _ROCK_H_
#define _ROCK_H_

#include "RenderableEntity.h"


class Rock : public RenderableEntity {
  public:
    void load(const sf::Texture *texture) override;
};

#endif //_ROCK_H_
