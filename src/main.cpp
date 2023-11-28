#define GL_SILENCE_DEPRECATION

#include <QtOpenGLWidgets/qopenglwidget.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qwidget.h>

#include <iostream>

#include "../include/OpenGLWidget.h"

void initializeWindow() {

}

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    // Set opengl options
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    //format.setVersion(4, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    // Set up window
    QWidget window;
    window.resize(600, 800);
    window.setWindowTitle("Title");
    window.show();

    
    OpenGLWidget testWidget(&window);
    testWidget.move(0, 0);
    testWidget.resize(600, 600);
    testWidget.show();

    return app.exec();
}
