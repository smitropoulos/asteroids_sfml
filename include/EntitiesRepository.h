//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _ENTITIESREPOSITORY_H_
#define _ENTITIESREPOSITORY_H_
#include <unordered_map>
#include "RenderableEntity.h"
#include "EntityType.h"

class EntitiesRepository {
  protected:
    std::unordered_map<EntityType, std::unique_ptr<RenderableEntity>> m_entities;
  public:
    static EntitiesRepository& getInstance() {

        static EntitiesRepository xInstance = EntitiesRepository();
        return xInstance;
    }

    [[nodiscard]] const std::unordered_map<EntityType, std::unique_ptr<RenderableEntity>>& entities() const;
    void addEntity(EntityType type, std::unique_ptr<RenderableEntity> entity);
};

#endif //_ENTITIESREPOSITORY_H_
