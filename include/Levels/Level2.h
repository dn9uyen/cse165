#ifndef LEVEL2_H
#define LEVEL2_H

#include "../BaseEntity.h"
#include "../Level.h"
#include "../PlayerBall.h"
#include <QtCore/qdebug.h>

class Level2 : public Level {
  public:
    Level2() {
        playerBallCount = 8;

        playerBall.setColor({0.65f, 0.65f, 0.65f});

        // Non mandatory
        constexpr int numBalls = 18;
        constexpr float angleOffset = 0.35f; // radians
        for (int i = 0; i < numBalls; i++) {
            float x = (0.3 * cos(i * angleOffset)) + -0.6f;
            float y = (0.3 * sin(i * angleOffset)) + -0.3f;
            entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {x, -y}));
        }
        for (int i = 0; i < numBalls; i++) {
            float x = (0.3 * cos(i * angleOffset)) + 0.6f;
            float y = (0.3 * sin(i * angleOffset)) + -0.3f;
            entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {x, -y}));
        }

        for (int i = 0; i < numBalls; i++) {
            float x = (0.7 * cos(i * 0.16f)) + 0.0f;
            float y = (0.7 * 0.5 * sin(i * 0.16f)) + 0.4f;
            entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {x, -y}));
        }

        // Mandatory
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.0f, -0.2f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.7f, 0.3f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.5f, 0.3f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.6f, 0.4f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.6f, 0.2f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.7f, 0.3f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.5f, 0.3f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.6f, 0.4f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.6f, 0.2f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        for (int i = 0; i < numBalls; i++) {
            float x = (0.6 * cos(i * 0.16f)) + 0.0f;
            float y = (0.6 * 0.5 * sin(i * 0.16f)) + 0.35f;
            entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {x, -y}));
        }

    }
};

#endif
