#include "../include/EntityManager.h"
#include <vector>

void EntityManager::addEntity(BaseEntity *entity) {
    entities.push_back(entity);
}

std::vector<BaseEntity *> EntityManager::getEntities() { return entities; }
