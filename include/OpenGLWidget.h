#ifndef OPENGL_WIDGET
#define OPENGL_WIDGET

#include "Level.h"
#include <QEvent>
#include <QOpenGLFunctions>
#include <QtCore/qtimer.h>
#include <QtOpenGLWidgets/qopenglwidget.h>

// Manages game state and graphics
class OpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions {
  private:
    Level *currentLevel;

  public:
    QTimer *timer;

    OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

    void initializeGL() override;
    void paintGL() override;
    void draw();
    void updateGame();
    Level *getCurrentLevel();

    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif
