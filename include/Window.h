#ifndef WINDOW_H
#define WINDOW_H

#include "OpenGLWidget.h"
#include <QtWidgets/qwidget.h>

class Window {
  private:
    QWidget *mainWidget;
    OpenGLWidget *openGLWidget;

  public:
    Window(int width, int height, const char *title);

    QWidget *getMainWindow();
    OpenGLWidget *getOpenGLWidget();
};

#endif
