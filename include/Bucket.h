#ifndef BASKET_H
#define BASKET_H

#define GL_SILENCE_DEPRECATION

#include "BaseEntity.h"
#include <QOpenGLFunctions>

class Basket : BaseEntity {
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
    Basket() {
        setColor({0.5f, 0.5f, 0.5f});
        setPos({0.0f, -0.9f});
    }

    void doMovement() {
        float moveAmount = 0.0025f * (moveDir ? 1 : -1);
        for (int i = 0; i < 8; i += 2) {
            verts[i] += moveAmount;
        }

        // Prevent from moving off screen
        if (verts[0] > 1.0f) {
            verts[0] -= moveAmount;
            moveDir = !moveDir;
            return;
        } else if (verts[2] < -1.0f) {
            verts[0] -= moveAmount;
            moveDir = !moveDir;
            return;
        }
    }

    void draw() {
        glColor3f(color.x(), color.y(), color.z());
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, verts);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};

#endif
