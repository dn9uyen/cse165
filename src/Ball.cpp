#include <qvectornd.h>
#define GL_SILENCE_DEPRECATION

#include "../include/Ball.h"
#include "../include/OpenGLWidget.h"
#include <QtCore/qlogging.h>
#include <cmath>

void Ball::draw() {
    constexpr int sides = 30;           // Defines how many sides the circle has
    constexpr int numVerts = sides + 2; // 2 = 1 duplicate vertex + 1 center
    constexpr float angleOffset = M_PI / (float)sides;
    GLfloat verts[numVerts * 2]; // *2 because x and y coords per vertex

    // Set center
    verts[0] = getPos().x();
    verts[1] = getPos().y();

    for (int i = 2; i < numVerts * 2; i++) {
        verts[i] = (radius * cos(i * angleOffset)) + getPos().x();
        verts[++i] = (radius * sin(i * angleOffset)) + getPos().y();
    }

    glColor3f(color.x(), color.y(), color.z());
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glDrawArrays(GL_TRIANGLE_FAN, 0, numVerts);
    glDisableClientState(GL_VERTEX_ARRAY);
}

float Ball::getRadius() { return radius; }

void Ball::setRadius(float newRadius) { radius = newRadius; }

void Ball::setColor(QVector3D newCol) {
    color = newCol;
}

void Ball::setHit(bool hit) { hitByPlayerBall = hit; };

bool Ball::getHitStatus() { return hitByPlayerBall; }

void Ball::setDeleteScheduled(bool b) { deleteScheduled = b; }

bool Ball::getDeleteScheduled() { return deleteScheduled; };

void Ball::setIsMandatory(bool b) { isMandatory = b; }
bool Ball::getMandatory() { return isMandatory; };
