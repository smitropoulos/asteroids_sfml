//
// Created by Stefanos Mitropoulos on 20/7/22.
//

#ifndef _ENTITIESREPOSITORY_H_
#define _ENTITIESREPOSITORY_H_
#include <vector>
#include "RenderableEntity.h"


class EntitiesRepository {
  protected:
    std::vector<std::unique_ptr<RenderableEntity>> m_entities;
  public:
    [[nodiscard]] const std::vector<std::unique_ptr<RenderableEntity>>& entities() const;
    void addEntity(std::unique_ptr<RenderableEntity> entity);
};

#endif //_ENTITIESREPOSITORY_H_
