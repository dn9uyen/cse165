#include "../include/Bucket.h"
#include "../include/Constants.h"

void Bucket::doMovement() {
    float moveAmount = bucketSpeed * (moveDir ? 1 : -1);
    for (int i = 0; i < 8; i += 2) {
        verts[i] += moveAmount;
        setPos({verts[0], getPos().y()});
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

void Bucket::draw() {
    glColor3f(color.x(), color.y(), color.z());
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
