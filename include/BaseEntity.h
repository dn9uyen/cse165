#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "OpenGLWidget.h"
#include <QVector2D>
#include <QtGui/qopenglfunctions.h>
#include <vector>

// Base class for all entities in the game. Also tracks all entities
class BaseEntity : protected QOpenGLFunctions {
  private:
    QVector2D pos;
    QVector2D vel;

  public:
    // Each entity needs to define how to draw itself
    virtual void draw(QOpenGLFunctions &f) = 0;

    // Getters and setters
    QVector2D getPos() { return pos; }
    void setPos(QVector2D newPos) { pos = newPos; }

    QVector2D getVel() { return vel; }
    void setVel(QVector2D newVel) { vel = newVel; }
};

#endif
