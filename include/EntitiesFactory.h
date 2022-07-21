//
// Created by Stefanos Mitropoulos on 21/7/22.
//

#ifndef _ENTITIESFACTORY_H_
#define _ENTITIESFACTORY_H_

#include <memory>
#include "EntityType.h"
#include "Player.h"
#include "RenderableEntity.h"
#include "TextureRepository.h"
#include "EntitiesRepository.h"
#include "Rock.h"


class EntitiesFactory {
  public:
    void makeEntity(const EntityType entityType) {

        switch ( entityType )
        {
            case EntityType::Player:
            {
                auto pl = std::make_unique<Player>();
                auto plTexture = TextureRepository::getInstance().provideTexture("player");
                pl->load(plTexture);
                EntitiesRepository::getInstance().addEntity(std::move(pl));
                break;
            }
            case EntityType::Rock:
                {
                    auto pl = std::make_unique<Rock>();
                    auto plTexture = TextureRepository::getInstance().provideTexture("rock");
                    pl->load(plTexture);
                    EntitiesRepository::getInstance().addEntity(std::move(pl));
                    break;
                }
            case EntityType::SmallRock:break;
            case EntityType::Bullet:break;
        }
    }
};

#endif //_ENTITIESFACTORY_H_
