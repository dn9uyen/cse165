#define GL_SILENCE_DEPRECATION

#include "../include/OpenGLWidget.h"
#include <iostream>

void OpenGLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void OpenGLWidget::paintGL() {
    // TODO: iterate through all BaseEntity::entities->draw()
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    GLfloat verts[] = {0.0f, 0.0f, 0.0f, 1.0f, 0.6f, 0.6f, 1.0f, 0.0f, 0.6f, -0.6f, 0.0f, -1.0f, -0.6f, -0.6f, -1.0f, 0.0f, -0.6f, 0.6f, 0.0f, 1.0f};
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 10);
    glDisableClientState(GL_VERTEX_ARRAY);

    glEnd();
}
