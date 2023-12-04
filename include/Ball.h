#ifndef BALL_H
#define BALL_H

#include "BaseEntity.h"

class Ball : public BaseEntity {
  protected:
    float radius;
    QVector3D color;
    bool hitByPlayerBall;
    bool deleteScheduled;
    bool isMandatory;

  public:
    Ball(float rad = 0.05, QVector3D col = {0.0f, 0.0f, 0.0f}, QVector2D position = {0.0f, 0.0f}, QVector2D velocity = {0.0f, 0.0f}) {
        radius = rad;
        color = col;
        setPos(position);
        setVel(velocity);
        hitByPlayerBall = false;
        isMandatory = false;
        deleteScheduled = false;
    }

    ~Ball() {}

    void draw();
    float getRadius();
    void setRadius(float newRadius);
    void setColor(QVector3D newCol);
    void setHit(bool hit);
    bool getHitStatus();
    void setDeleteScheduled(bool b);
    bool getDeleteScheduled();
    void setIsMandatory(bool b);
    bool getMandatory();
};

#endif
