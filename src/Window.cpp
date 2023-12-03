#include "../include/Window.h"
#include <QColor>
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
    ballCount->move(75, 610);
    ballCount->show();

    score = new QLabel(this);
    score->setText("Score: 00000");
    score->move(260, 610);
    score->show();

    status = new QLabel(this);
    status->setText("Status: ..............");
    status->move(450, 610);
    status->show();

    currentLevel = new QLabel(this);
    currentLevel->setText("Current level: 00");
    currentLevel->move(250, 680);
    currentLevel->show();

    levels[0] = new QPushButton(this);
    levels[0]->setText("Level 1");
    levels[0]->move(50, 640);
    levels[0]->show();
    QObject::connect(levels[0], &QPushButton::clicked, [this] { openGLWidget->setLevel(1); });

    levels[1] = new QPushButton(this);
    levels[1]->setText("Level 2");
    levels[1]->move(150, 640);
    levels[1]->show();
    QObject::connect(levels[1], &QPushButton::clicked, [this] { openGLWidget->setLevel(2); });

    levels[2] = new QPushButton(this);
    levels[2]->setText("Level 3");
    levels[2]->move(250, 640);
    levels[2]->show();
    QObject::connect(levels[2], &QPushButton::clicked, [this] { openGLWidget->setLevel(3); });

    levels[3] = new QPushButton(this);
    levels[3]->setText("Level 4");
    levels[3]->move(350, 640);
    levels[3]->show();
    QObject::connect(levels[3], &QPushButton::clicked, [this] { openGLWidget->setLevel(4); });

    levels[4] = new QPushButton(this);
    levels[4]->setText("Level 5");
    levels[4]->move(450, 640);
    levels[4]->show();
    QObject::connect(levels[4], &QPushButton::clicked, [this] { openGLWidget->setLevel(5); });

    // Gui update loop
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
    int levelStatus = openGLWidget->getCurrentLevel()->getStatus();
    switch (levelStatus) {
    case 0:
        str = "Status: Playing";
        break;
    case -1:
        str = "Status: Failed";
        levels[openGLWidget->getCurrentLevelInt() - 1]->setStyleSheet("QPushButton { border: 2px solid red }");
        break;
    case 1:
        str = "Status: Passed!";
        levels[openGLWidget->getCurrentLevelInt() - 1]->setStyleSheet("QPushButton { border: 2px solid green }");
        break;
    }
    status->setText(str.c_str());

    str = "Current level: " + std::to_string(openGLWidget->getCurrentLevelInt());
    currentLevel->setText(str.c_str());
}

OpenGLWidget *Window::getOpenGLWidget() { return openGLWidget; }
