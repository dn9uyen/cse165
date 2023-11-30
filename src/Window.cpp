#include "../include/Window.h"
#include <QtCore/qtimer.h>

Window::Window(int width, int height, const char *title) {
    mainWidget = new QWidget;
    mainWidget->resize(width, height);
    mainWidget->setWindowTitle(title);
    mainWidget->show();

    // Has to be called after showing main window or seg faults
    openGLWidget = new OpenGLWidget(mainWidget);
    openGLWidget->move(0, 0);
    openGLWidget->resize(width, height);
    openGLWidget->show();


}

QWidget *Window::getMainWindow() { return mainWidget; }

OpenGLWidget *Window::getOpenGLWidget() { return openGLWidget; }
