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
    int* playerBallCount = new int(1);
    PlayerBall playerBall;
    Cannon cannon;
    Basket basket;
    std::vector<BaseEntity *> entities;

  public:
    virtual void update() = 0;
    virtual void draw() = 0;

    void processEvent(QEvent *event) {
        qDebug() << event->type();
        switch (((QKeyEvent *)event)->key()) {
        case Qt::Key_Right:
            cannon.rotate("right");
            qDebug() << "right";
            break;
        case Qt::Key_Left:
            cannon.rotate("left");
            qDebug() << "left";
            break;
        case Qt::Key_Down:
            if (playerBall.inCannon) {
                playerBall.launch();
                qDebug() << "launch";
            }
            break;
        }
    }

    int* getPlayerBallCount() {
        return playerBallCount;
    };
};

#endif
