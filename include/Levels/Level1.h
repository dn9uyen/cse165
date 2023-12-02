#ifndef LEVEL1_H
#define LEVEL1_H

#include "../BaseEntity.h"
#include "../Level.h"
#include "../PlayerBall.h"
#include <QtCore/qdebug.h>

class Level1 : public Level {
  public:
    Level1() {
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.4f, -0.2f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.3f, -0.4f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.2f, -0.4f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.1f, -0.4f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.0f, -0.4f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.2f, -0.4f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.2f, -0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.2f, -0.6f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.2f, -0.8f}));
        playerBall.setPos({0.0f, 0.9f});
        playerBall.setVel({0.0005f, -0.02f});
        playerBall.setColor({0.7f, 0.0f, 0.5f});
    }

    void update() {
        basket.doMovement();
        if (playerBall.inCannon) {
            playerBall.setPos(cannon.getTip());
        } else {
            playerBall.doPhysics(entities);
            if (playerBall.getPos().y() == -1.0f) {
                playerBall.inCannon = true;
                playerBall.setVel({0.0f, 0.0f});
                // decrease ball count
            }
        }
    }

    void draw() {
        cannon.draw();
        playerBall.draw();
        basket.draw();
        for (BaseEntity *entity : entities) {
            entity->draw();
        }
    };
};

#endif
