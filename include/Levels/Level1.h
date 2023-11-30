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
        playerBall.setVel({0.005f, 0.03f});
        playerBall.setColor({0.7f, 0.0f, 0.5f});
    }

    void update() { playerBall.update(entities); }

    void draw() {
        playerBall.draw();
        for (BaseEntity *entity : entities) {
            entity->draw();
        }
    };
};

#endif