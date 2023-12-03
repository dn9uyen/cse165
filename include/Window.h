#ifndef WINDOW_H
#define WINDOW_H

#include "OpenGLWidget.h"
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QtWidgets/qwidget.h>

class Window : public QWidget {
  private:
    QTimer *timer;
    OpenGLWidget *openGLWidget;
    QLabel *ballCount;
    QLabel *score;
    QLabel *status;
    QLabel *currentLevel;
    QPushButton* levels[5];

  public:
    Window(int width, int height, const char *title);

    QWidget *getMainWindow();
    OpenGLWidget *getOpenGLWidget();
    void updateLabels();
};

#endif
