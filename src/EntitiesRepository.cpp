//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include "../include/EntitiesRepository.h"


const std::unordered_map<EntityType, std::unique_ptr<RenderableEntity>>& EntitiesRepository::entities() const {

    return m_entities;
}

void EntitiesRepository::addEntity(EntityType type, std::unique_ptr<RenderableEntity> entity) {

    m_entities.insert({type, std::move(entity)});
}
