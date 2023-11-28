#ifndef CUSTOM_OPENGL_WIDGET
#define CUSTOM_OPENGL_WIDGET

#include <QOpenGLFunctions>
#include <QtOpenGLWidgets/qopenglwidget.h>

// Main widget that handles drawing game graphics
class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  public:
    OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}
    

  protected:
    void initializeGL() override;
    void paintGL() override;
};

#endif
