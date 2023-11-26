#ifndef CUSTOM_OPENGL_WIDGET
#define CUSTOM_OPENGL_WIDGET

#include <QOpenGLFunctions>
#include <QtOpenGLWidgets/qopenglwidget.h>

class CustomOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  public:
    CustomOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

  protected:
    void initializeGL() override;
};

#endif
