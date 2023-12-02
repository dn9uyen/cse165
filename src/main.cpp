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
    Window window(600, 800, "Title");

    //window.getOpenGLWidget()->timer->start(1000);

    // EntityManager entityManager;
    // entityManager.addEntity(new Ball(0.1, {0.5f, 0.2f, 0.3f}, {0.2f, 0.2}));
    // entityManager.addEntity(new Ball(0.1, {0.1f, 0.5f, 0.4f}, {0.0f, 0.0}));
    // entityManager.addEntity(new Ball(0.1, {0.3f, 0.4f, 0.7f}, {-0.2f,
    // -0.2}));

    // QTimer timer;
    // QObject::connect(&timer, &QTimer::timeout, &mainWidget,
    //                  [&] { game.update(entityManager.getEntities()[0]); });
    // timer.start(1000);

    // OpenGLWidget testWidget(&mainWidget);
    // testWidget.move(0, 0);
    // testWidget.resize(600, 600);
    // testWidget.show();

    return app.exec();
}
