#ifndef CUSTOM_OPENGL_WIDGET
#define CUSTOM_OPENGL_WIDGET

#include <QOpenGLFunctions>
#include <QtOpenGLWidgets/qopenglwidget.h>

// Main widget that handles drawing game graphics
class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  private:
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

  protected:
    void initializeGL() override;
    void paintGL() override;

  public:
    OpenGLWidget(QWidget *parent) : QOpenGLWidget(parent) {}

    QOpenGLFunctions* getFunctions() { return f; }
};

#endif
