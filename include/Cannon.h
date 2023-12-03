#ifndef CANNON_H
#define CANNON_H

#define GL_SILENCE_DEPRECATION

#include "BaseEntity.h"
#include <QOpenGLFunctions>

class Cannon : public BaseEntity {
  private:
    QVector2D tip = {0.0f, 0.7f};
    GLfloat verts[8] = {
        0.1f, 1.1f,
        -0.1f, 1.1f,
        -0.05f, 0.7f,
        0.05f, 0.7f};
    GLubyte indices[6] = {
        0, 1, 2,
        0, 3, 2};

  public:
    Cannon() {
        setColor({0.5f, 0.5f, 0.5f});
        setPos({0.0f, 1.1f});
    }

    void rotate(bool dir);
    void draw();

    QVector2D getTip();
};

#endif
