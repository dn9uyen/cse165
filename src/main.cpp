#define GL_SILENCE_DEPRECATION

#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>
#include <QApplication>
#include <QPushButton>

#include <iostream>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QPushButton button ("Hello world");
    button.show();

    return app.exec();
}
