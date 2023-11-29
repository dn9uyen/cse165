#include "../include/Window.h"

Window::Window(int width, int height, const char *title) {
    mainWindow = new QWidget;
    mainWindow->resize(width, height);
    mainWindow->setWindowTitle(title);
    mainWindow->show();
    // Has to be called after showing main window or seg faults
    openGLWidget = new OpenGLWidget(mainWindow);
    openGLWidget->move(0, 0);
    openGLWidget->resize(width, height);
    openGLWidget->show();
}

QWidget *Window::getMainWindow() { return mainWindow; }

OpenGLWidget *Window::getOpenGLWidget() { return openGLWidget; }
