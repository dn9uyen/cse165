#include "../include/CustomOpenGLWidget.h"

void CustomOpenGLWidget::initializeGL() {
    initializeOpenGLFunctions(); 
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
}
