#include <qvectornd.h>
#define GL_SILENCE_DEPRECATION

#include "../include/Ball.h"
#include "../include/OpenGLWidget.h"
#include <QtCore/qlogging.h>
#include <cmath>

void Ball::draw() {
    std::vector<GLfloat> colors = {color.x(), color.y(), color.z()};
    constexpr int sides = 30;           // Defines how many sides the circle has
    constexpr int numVerts = sides + 2; // 2 = 1 duplicate vertex + 1 center
    constexpr float angleOffset = M_PI / (float)sides;
    GLfloat verts[numVerts * 2]; // *2 because x and y coords per vertex

    // Set center

    verts[0] = getPos().x();
    verts[1] = getPos().y();

    for (int i = 2; i < numVerts * 2; i+=2) {
        verts[i] = (radius * cos(i * angleOffset)) + getPos().x();
        verts[i+1] = (radius * sin(i * angleOffset)) + getPos().y();
    }

    for (int i = 1; i < numVerts; i++) {
        colors.push_back(color.x()-0.3f);
        colors.push_back(color.y()-0.3f);
        colors.push_back(color.z()-0.3f);
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glColorPointer(3, GL_FLOAT, 0, &colors[0]);
    glDrawArrays(GL_TRIANGLE_FAN, 0, numVerts);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
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
