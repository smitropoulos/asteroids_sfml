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
                pl->setPosition(sf::Vector2i(100,100));
                EntitiesRepository::getInstance().addEntity(std::move(pl));
                break;
            }
            case EntityType::Rock:break;
            case EntityType::SmallRock:break;
            case EntityType::Bullet:break;
        }
    }
};

#endif //_ENTITIESFACTORY_H_
