#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "BaseEntity.h"
#include <QtGui/qopenglfunctions.h>
#include <vector>

class EntityManager {
  private:
    static inline std::vector<BaseEntity *> entities;

  public:
    void addEntity(BaseEntity *entity);

    static std::vector<BaseEntity *> getEntities();
};

#endif
