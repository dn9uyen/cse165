#ifndef LEVEL_H
#define LEVEL_H

#include "Ball.h"
#include "BaseEntity.h"
#include "PlayerBall.h"
#include <vector>

// Base class for all levels in the game
class Level {
  protected:
    PlayerBall playerBall;
    std::vector<BaseEntity *> entities;

  public:
    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif
