#ifndef LEVEL_H
#define LEVEL_H

#include "Ball.h"
#include "BaseEntity.h"
#include "Bucket.h"
#include "Cannon.h"
#include "PlayerBall.h"
#include <QEvent>
#include <QKeyEvent>
#include <vector>

// Base class for all levels in the game
class Level {
  protected:
    int playerBallCount;
    PlayerBall playerBall;
    Cannon cannon;
    Bucket bucket;
    std::vector<BaseEntity *> entities;

  public:
    Level() {
        playerBallCount = 1;
    }

    void update();
    void draw();
    void processEvent(QEvent *event);
    int getPlayerBallCount();
};
#endif
