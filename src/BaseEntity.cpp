#include "../include/BaseEntity.h"

QVector2D BaseEntity::getPos() { return pos; }

void BaseEntity::setPos(QVector2D newPos) { pos = newPos; }

QVector2D BaseEntity::getVel() { return vel; }

void BaseEntity::setVel(QVector2D newVel) { vel = newVel; }
