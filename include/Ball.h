#ifndef BALL_H
#define BALL_H

#include "BaseEntity.h"
#include "OpenGLWidget.h"
#include <OpenGL/OpenGL.h>

class Ball : public BaseEntity {
  private:
    float size;
    float radius;
    QVector3D color;

  public:
    Ball() {
        setPos({0.0f, 0.0f});
        setVel({0.0f, 0.0f});
        radius = 0.25f;
        color = {0.0f, 0.0f, 0.0f};
    }

    void draw(QOpenGLFunctions &f);

    // getters and setters
    float getRadius() { return radius; }
    void setRadius(float newRadius) { radius = newRadius; }
};

#endif
