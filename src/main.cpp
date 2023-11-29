#define GL_SILENCE_DEPRECATION

#include <QtCore/qobject.h>
#include <QtOpenGLWidgets/qopenglwidget.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qwidget.h>

#include <iostream>

#include "../include/Ball.h"
#include "../include/EntityManager.h"
#include "../include/Game.h"
#include "../include/MainWidget.h"
#include "../include/OpenGLWidget.h"

void initializeWindow() {}

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    // Set opengl options
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    // format.setVersion(4, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    // Set up window widget
    MainWidget mainWidget;
    mainWidget.show();

    Game game;

    EntityManager entityManager;
    entityManager.addEntity(new Ball(0.1, {0.5f, 0.2f, 0.3f}, {0.2f, 0.2}));
    entityManager.addEntity(new Ball(0.1, {0.1f, 0.5f, 0.4f}, {0.0f, 0.0}));
    entityManager.addEntity(new Ball(0.1, {0.3f, 0.4f, 0.7f}, {-0.2f, -0.2}));

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &mainWidget,
                     [&] { game.update(entityManager.getEntities()[0]); });
    timer.start(1000);

    OpenGLWidget testWidget(&mainWidget);
    testWidget.move(0, 0);
    testWidget.resize(600, 600);
    testWidget.show();

    return app.exec();
}
