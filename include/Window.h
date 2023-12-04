#ifndef WINDOW_H
#define WINDOW_H

#include "OpenGLWidget.h"
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QtWidgets/qwidget.h>

class Window : public QWidget {
  private:
    QTimer *timer;
    OpenGLWidget *openGLWidget;
    QLabel *ballCount;
    QLabel *score;
    QLabel *status;
    QLabel *currentLevel;
    QPushButton* levels[5];

  public:
    Window(int width, int height, const char *title);

    ~Window() {
        delete timer;
        delete openGLWidget;
        delete ballCount;
        delete score;
        delete status;
        delete currentLevel;
        for (auto a : levels) {
            delete a;
        }
        delete[] &levels;
    }

    QWidget *getMainWindow();
    OpenGLWidget *getOpenGLWidget();
    void updateLabels();
};

#endif
