#define GL_SILENCE_DEPRECATION

#include <QtOpenGLWidgets/qopenglwidget.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qwidget.h>

#include <iostream>

#include "../include/CustomOpenGLWidget.h"

void initializeWindow() {

}

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    // Set opengl options
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(4, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    // Set up window
    QWidget window;
    window.resize(320, 240);
    window.setWindowTitle("Title");
    window.show();

    QPushButton button("test", &window);
    button.move(10, 10);
    button.show();

    CustomOpenGLWidget testWidget(&window);
    testWidget.move(100, 100);
    testWidget.show();

    return app.exec();
}
