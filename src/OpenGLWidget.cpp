#define GL_SILENCE_DEPRECATION

#include "../include/OpenGLWidget.h"
#include "../include/Levels/Level1.h"
#include "../include/Constants.h"
#include <QtCore/qobject.h>

void OpenGLWidget::initializeGL() {
    currentLevel = new Level1;

    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &OpenGLWidget::updateGame);
    timer->start(timeStep); // Defines game fps
}

void OpenGLWidget::paintGL() { currentLevel->draw(); }

void OpenGLWidget::updateGame() {
    currentLevel->update();
    update();
}
