#ifndef BASKET_H
#define BASKET_H

#define GL_SILENCE_DEPRECATION

#include "BaseEntity.h"
#include <QOpenGLFunctions>

class Bucket : public BaseEntity {
  private:
    bool moveDir = true; // true = move right
    GLfloat verts[8] = {
        0.3f, -0.9f,
        -0.3f, -0.9f,
        -0.25f, -1.0f,
        0.25f, -1.0f};
    GLubyte indices[6] = {
        0, 1, 2,
        0, 3, 2};

  public:
    Bucket() {
        setColor({0.5f, 0.5f, 0.5f});
        setPos({0.0f, -0.9f});
    }

    void doMovement();
    void draw();
};

#endif
