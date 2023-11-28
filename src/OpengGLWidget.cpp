#define GL_SILENCE_DEPRECATION

#include "../include/BaseEntity.h"
#include "../include/EntityManager.h"
#include "../include/OpenGLWidget.h"
#include <iostream>

void OpenGLWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void OpenGLWidget::paintGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    for (BaseEntity *entity : EntityManager::getEntities()) {
        entity->draw(*f);
    }
    glEnd();
}
