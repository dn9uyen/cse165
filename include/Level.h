#ifndef LEVEL_H
#define LEVEL_H

#include "EntityManager.h"

// Base class for all levels in the game
class Level {
  private:
    EntityManager entityManager;

  public:
    void update();
};

#endif
