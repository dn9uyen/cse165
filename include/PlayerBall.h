#ifndef PLAYER_BALL_H
#define PLAYER_BALL_H

#define GL_SILENCE_DEPRECATION

#include "Ball.h"
#include "Constants.h"
#include <QtCore/qdebug.h>

class PlayerBall : public Ball {
  private:
    bool inCannon = true;

  public:
    void launch();
    void doPhysics(std::vector<BaseEntity *> entities);
    bool getCannonStatus();
    void setCannonstatus(bool status);
};

#endif
