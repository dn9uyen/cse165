#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include <QVector2D>
#include <qvectornd.h>
#include <vector>

// Base class for all entities in the game
class BaseEntity {
  protected:
    QVector3D color;
    QVector2D pos;
    QVector2D vel;

  public:
    ~BaseEntity() {}

    virtual void draw() = 0;
    void update();

    QVector3D getColor();
    void setColor(QVector3D col);

    QVector2D getPos();
    void setPos(QVector2D newPos);

    QVector2D getVel();
    void setVel(QVector2D newVel);
};

#endif
