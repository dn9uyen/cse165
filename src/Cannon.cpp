#include "../include/Cannon.h"

QVector2D Cannon::getTip() { return tip; }

void Cannon::rotate(bool dir) {
    // dir true = turn right
    constexpr QVector2D rotPoint = {0.0f, 1.1f};
    float angle = 0.02f;
    if (dir == false) {
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
        rotate(true);
        return;
    } else if (verts[7] > 1.0f) {
        rotate(false);
        return;
    }
}

void Cannon::draw() {
    glColor3f(color.x(), color.y(), color.z());
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
    glDisableClientState(GL_VERTEX_ARRAY);
}
