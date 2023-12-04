#include <QtCore/qdebug.h>
#define GL_SILENCE_DEPRECATION

#include "../include/Constants.h"
#include "../include/Levels/Level1.h"
#include "../include/Levels/Level2.h"
#include "../include/Levels/Level3.h"
#include "../include/Levels/Level4.h"
#include "../include/Levels/Level5.h"
#include "../include/OpenGLWidget.h"
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

BaseLevel *OpenGLWidget::getCurrentLevel() { return currentLevel; }

int OpenGLWidget::getCurrentLevelInt() { return currentLevelInt; }

void OpenGLWidget::setLevel(int l) {
    delete currentLevel;
    switch (l) {
    case 1:
        currentLevel = new Level1;
        break;
    case 2:
        currentLevel = new Level2;
        break;
    case 3:
        currentLevel = new Level3;
        break;
    case 4:
        currentLevel = new Level4;
        break;
    case 5:
        currentLevel = new Level5;
        break;
    default:
        return;
    }
    currentLevelInt = l;
}
