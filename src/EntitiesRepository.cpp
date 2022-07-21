//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#include "../include/EntitiesRepository.h"


const std::vector<std::unique_ptr<RenderableEntity>>& EntitiesRepository::entities() const {

    return m_entities;
}

void EntitiesRepository::addEntity(std::unique_ptr<RenderableEntity> entity) {
    m_entities.push_back(std::move(entity));
}
