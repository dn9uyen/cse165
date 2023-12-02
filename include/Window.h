#ifndef WINDOW_H
#define WINDOW_H

#include "OpenGLWidget.h"
#include <QLabel>
#include <QTimer>
#include <QtWidgets/qwidget.h>

class Window : QWidget {
  private:
    QTimer *timer;
    OpenGLWidget *openGLWidget;
    QLabel *ballCount;
    QLabel *score;

  public:
    Window(int width, int height, const char *title);

    QWidget *getMainWindow();
    OpenGLWidget *getOpenGLWidget();
    void updateLabels();
};

#endif
