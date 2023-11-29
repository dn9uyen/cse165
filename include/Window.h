#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "OpenGLWidget.h"
#include <QtWidgets/qwidget.h>

class Window {
  private:
    QWidget *mainWindow;
    OpenGLWidget *openGLWidget;

  public:
    Window(int width, int height, const char *title);

    QWidget *getMainWindow();
    OpenGLWidget *getOpenGLWidget();
};

#endif
