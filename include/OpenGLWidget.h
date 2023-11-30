#ifndef OPENGL_WIDGET
#define OPENGL_WIDGET

#include <QOpenGLFunctions>
#include <QtCore/qtimer.h>
#include <QtOpenGLWidgets/qopenglwidget.h>
#include "Level.h"

// Manages game state and graphics
class OpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions {
  private:
  public:
    QTimer *timer;

    Level* currentLevel;

    OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

    void initializeGL() override;
    void paintGL() override;
    void draw();
    void updateGame();
};

#endif
