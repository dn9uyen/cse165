#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "OpenGLWidget.h"
#include <QVector2D>
#include <QtGui/qopenglfunctions.h>
#include <vector>

// Base class for all entities in the game
class BaseEntity : protected QOpenGLFunctions {
  private:
    QVector2D pos;
    QVector2D vel;

  public:
    // Each entity needs to define how to draw itself
    virtual void draw(QOpenGLFunctions &f) = 0;

    virtual QVector2D getPos();
    virtual void setPos(QVector2D newPos);

    virtual QVector2D getVel();
    virtual void setVel(QVector2D newVel);
};

#endif
