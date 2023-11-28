#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include <QVector2D>
#include <vector>

// Base class for all entities in the game. Also tracks all entities
class BaseEntity {
  private:
    QVector2D pos;
    QVector2D vel;
    static std::vector<BaseEntity *> entities;

  public:
    // New entity needs to be added to the list when created
    BaseEntity(BaseEntity *entity) { entities.push_back(entity); }

    // Erase self from list when destroyed
    ~BaseEntity() { std::erase(entities, this); }

    // Each entity needs to define how to draw itself
    virtual void draw() = 0;

    // Getters and setters
    QVector2D getPos() { return pos; }
    void setPos(QVector2D newPos) { pos = newPos; }

    QVector2D getVel() { return vel; }
    void setVel(QVector2D newVel) { vel = newVel; }

    std::vector<BaseEntity *> getEntities() const { return entities; }
    void addEntity(BaseEntity *entity) { entities.push_back(entity); }
};

#endif
