#ifndef CANNON_H
#define CANNON_H

#define GL_SILENCE_DEPRECATION

#include "BaseEntity.h"
#include <QOpenGLFunctions>
#include <string>

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

    QVector2D getTip() { return tip; }

    void rotate(std::string dir) {
        constexpr QVector2D rotPoint = {0.0f, 1.1f};
        float angle = 0.02f;
        if (dir == "left") {
            angle *= -1;
        }

        for (int i = 0; i < 8; i += 2) {
            // Rotation matrix
            verts[i] = cosf(angle) * (verts[i] - rotPoint.x()) - sinf(angle) * (verts[i + 1] - rotPoint.y()) + rotPoint.x();
            verts[i + 1] = sinf(angle) * (verts[i] - rotPoint.x()) + cosf(angle) * (verts[i + 1] - rotPoint.y()) + rotPoint.y();
        }

        tip = {(verts[4] + verts[6]) / 2, (verts[5] + verts[7]) / 2};

        // Prevent from rotating off screen
        if (verts[5] > 1.0f) {
            rotate("right");
            return;
        } else if (verts[7] > 1.0f) {
            rotate("left");
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
