#ifndef LEVEL3_H
#define LEVEL3_H

#include "../BaseEntity.h"
#include "../BaseLevel.h"
#include "../PlayerBall.h"
#include <QtCore/qdebug.h>

class Level3 : public BaseLevel {
  public:
    Level3() {
        playerBallCount = 6;

        playerBall.setColor({0.65f, 0.65f, 0.65f});

        // Non mandatory
        for (int i = 0; i < 15; i++) {
            entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.9f + 0.05f * i, 0.7f - 0.1f * i}));
            entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.9f - 0.05f * i, 0.7f - 0.1f * i}));
        }

        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.0f, 0.0f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.5f, 0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.5f, 0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.3f, 0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.3f, 0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.2f, 0.3f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.2f, 0.3f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.15f, 0.15f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.15f, 0.15f}));

        // Mandatory
        for (int i = 0; i < 5; i++) {
            entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.95f + 0.05f * i, 0.4f - 0.3f * i}));
            dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
            entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.95f - 0.05f * i, 0.4f - 0.3f * i}));
            dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        }
        for (int i = 0; i < 5; i++) {
            entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.4f + 0.05f * i, 0.4f - 0.2f * i}));
            dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
            entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.4f - 0.05f * i, 0.4f - 0.2f * i}));
            dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        }
    }
};

#endif
