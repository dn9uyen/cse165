#include "../include/Window.h"
#include <QtGui/qsurfaceformat.h>
#include <qapplication.h>

int main(int argc, char **argv) {
    // Set opengl options
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setSwapInterval(10);
    // format.setVersion(4, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    QApplication app(argc, argv);

    // Create window
    Window window(600, 700, "Peggle Clone");

    return app.exec();
}
