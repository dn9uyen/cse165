#ifndef BALL_H
#define BALL_H

#include "BaseEntity.h"

class Ball : public BaseEntity {
  private:
    float radius;
    QVector3D color;

  public:
    Ball(float rad = 0.25, QVector3D col = {0.0f, 0.0f, 0.0f},
         QVector2D position = {0.0f, 0.0f},
         QVector2D velocity = {0.0f, 0.0f} ) {
        radius = rad;
        color = col;
        setPos(position);
        setVel(velocity);
    }

    void draw(QOpenGLFunctions &f);

    float getRadius();
    void setRadius(float newRadius);
};

#endif
