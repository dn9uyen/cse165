#include <QtCore/qdebug.h>
#define GL_SILENCE_DEPRECATION

#include "../include/OpenGLWidget.h"
#include "../include/Constants.h"
#include "../include/Levels/Level1.h"
#include "../include/Window.h"
#include <QtCore/qobject.h>

void OpenGLWidget::initializeGL() {
    this->installEventFilter(this);
    grabKeyboard();
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

bool OpenGLWidget::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        currentLevel->processEvent(event);
    }
    return false;
}

Level* OpenGLWidget::getCurrentLevel() {return currentLevel;}
