#ifndef PLAYER_BALL_H
#define PLAYER_BALL_H

#include "Ball.h"
#include "Constants.h"
#include <QtCore/qdebug.h>

class PlayerBall : public Ball {
  public:
    void update(std::vector<BaseEntity *> entities) {
        // Gravity and x movement
        setVel({getVel().x(), getVel().y() + gravity * timeStep});
        setPos({getPos().x() + getVel().x() * timeStep,
                getPos().y() + (getVel().y() + timeStep * gravity / 2)});

        // Check collisions
        for (BaseEntity *entity : entities) {
            float distX = getPos().x() - entity->getPos().x();
            float distY = getPos().y() - entity->getPos().y();
            float dist = sqrtf(distX * distX + distY * distY);

            float radius = dynamic_cast<Ball *>(entity)->getRadius();
            if (dist <= getRadius() + radius) {
                
            }
        }

        // Check y bounce
        if (getPos().y() < -1.0f) {
            setVel({getVel().x(), getVel().y() * -0.9f});
            setPos({getPos().x(), -1.0f});
        } else if (getPos().y() > 1.0f) {
            setVel({getVel().x(), getVel().y() * -0.9f});
            setPos({getPos().x(), 1.0f});
        }

        // Check x bounce
        if (getPos().x() < -1.0f) {
            setPos({-1.0f, getPos().y()});
            setVel({getVel().x() * -0.9f, getVel().y()});
        } else if (getPos().x() > 1.0f) {
            setPos({1.0f, getPos().y()});
            setVel({getVel().x() * -0.9f, getVel().y()});
        }

        // if (getVel().x() < 0.0001f) { setVel({0, getVel().y()}); }
        // if (getVel().y() < 0.0001f) { setVel({getVel().x(), 0}); }
    }
};

#endif
