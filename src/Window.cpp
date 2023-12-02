#include "../include/Window.h"
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
    ballCount->move(250, 610);
    ballCount->show();

    score = new QLabel(this);
    score->setText("Score: 00000");
    score->move(250, 630);
    score->show();

    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, [this] { updateLabels(); });
    timer->start(100);
}

void Window::updateLabels() {
    // Update ball count
    std::string str = "Balls: " + std::to_string(*openGLWidget->getBallCount());
    ballCount->setText(str.c_str());

    // Update score
    score->setText("Score: 9999");
}

OpenGLWidget *Window::getOpenGLWidget() { return openGLWidget; }
