#ifndef LEVEL1_H
#define LEVEL1_H

#include "../BaseEntity.h"
#include "../Level.h"
#include "../PlayerBall.h"
#include <QtCore/qdebug.h>

class Level1 : public Level {
  public:
    Level1() {
        playerBallCount = 5;

        playerBall.setColor({0.65f, 0.65f, 0.65f});

        // Non mandatory
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.7f, 0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.3f, 0.6f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.1f, 0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.5f, 0.4f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.9f, 0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.7f, -0.6f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.3f, -0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.1f, -0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.5f, -0.4f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.9f, -0.5f}));


        // Mandatory
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.7f, 0.0f}));
        dynamic_cast<Ball*>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.3f, 0.2f}));
        dynamic_cast<Ball*>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.1f, 0.0f}));
        dynamic_cast<Ball*>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.5f, 0.2f}));
        dynamic_cast<Ball*>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.9f, 0.0f}));
        dynamic_cast<Ball*>(entities.back())->setIsMandatory(true);

    }
};

#endif
