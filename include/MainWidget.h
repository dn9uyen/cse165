#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QTimer>
#include <QtCore/qobject.h>
#include <QtWidgets/qwidget.h>

class MainWidget : public QWidget {
  public:
    MainWidget(int width = 600, int height = 800, const char *title = "Title") {
        this->resize(width, height);
        this->setWindowTitle(title);
    }
};

#endif
