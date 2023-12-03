#include "../include/Window.h"
#include <QtCore/qdebug.h>
#include <QtCore/qobject.h>
#include <string>

Window::Window(int width, int height, const char *title) : QWidget(0) {
    this->resize(width, height);
    this->setWindowTitle(title);
    this->show();

    // Has to be called after showing main window or seg faults
    openGLWidget = new OpenGLWidget(this);
    openGLWidget->move(0, 0);
    openGLWidget->resize(width, width);
    openGLWidget->show();

    ballCount = new QLabel(this);
    ballCount->setText("Balls: 000");
    ballCount->move(100, 610);
    ballCount->show();

    score = new QLabel(this);
    score->setText("Score: 00000");
    score->move(275, 610);
    score->show();

    status = new QLabel(this);
    status->setText("Status: ..............");
    status->move(450, 610);
    status->show();

    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &Window::updateLabels);
    timer->start(100);
}

void Window::updateLabels() {
    // Update ball count
    std::string str = "Balls: " + std::to_string(openGLWidget->getCurrentLevel()->getPlayerBallCount());
    ballCount->setText(str.c_str());

    // Update score
    str = "Score: " + std::to_string(openGLWidget->getCurrentLevel()->getScore());
    score->setText(str.c_str());

    // Update status
    switch (openGLWidget->getCurrentLevel()->getStatus()) {
    case 0:
        str = "Status: Playing";
        break;
    case -1:
        str = "Status: Failed";
        break;
    case 1:
        str = "Status: Passed!";
        break;
    }
    status->setText(str.c_str());
}

OpenGLWidget *Window::getOpenGLWidget() { return openGLWidget; }
