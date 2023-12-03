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
    int score;
    int status; // -1=failed, 0=tbd, 1=passed
    PlayerBall playerBall;
    Cannon cannon;
    Bucket bucket;
    std::vector<BaseEntity *> entities;

  public:
    Level() {
        playerBallCount = 1;
        score = 0;
        status = 0;
    }

    ~Level() {
        for (BaseEntity* entity : entities) {
            delete entity;
        }
    }

    void update();
    void draw();
    void processEvent(QEvent *event);
    int getPlayerBallCount();
    int getScore();
    int getStatus();
    void setStatus(int s);
};
#endif
