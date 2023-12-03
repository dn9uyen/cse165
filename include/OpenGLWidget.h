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
    int currentLevelInt;

  public:
    QTimer *timer;

    OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {
        currentLevelInt = 1;
    }

    void initializeGL() override;
    void paintGL() override;
    void draw();
    void updateGame();
    Level *getCurrentLevel();
    int getCurrentLevelInt();
    void setLevel(int l);

    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif
