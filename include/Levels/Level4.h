#ifndef LEVEL4_H
#define LEVEL4_H

#include "../BaseEntity.h"
#include "../BaseLevel.h"
#include "../PlayerBall.h"
#include <QtCore/qdebug.h>

class Level4 : public BaseLevel {
  public:
    Level4() {
        playerBallCount = 6;

        playerBall.setColor({0.65f, 0.65f, 0.65f});

        // Non mandatory
        for (int i = 0; i < 15; i++) {
            entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.9f + 0.05f * i, -0.7f + 0.1f * i}));
            entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.9f - 0.05f * i, -0.7f + 0.1f * i}));
            entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.8f + 0.115f * i, -0.75f}));
        }
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.8f, 0.75f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.8f, 0.75f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.85f, 0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.85f, 0.5f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.7f, 0.3f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.7f, 0.3f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.8f, 0.0f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.8f, 0.0f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.4f, -0.2f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.4f, -0.2f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.3f, -0.4f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.3f, -0.4f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.2f, -0.6f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.2f, -0.6f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {0.1f, 0.0f}));
        entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {-0.1f, 0.0f}));

        // Mandatory
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.6f, 0.6f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.6f, 0.6f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.15f, 0.2f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.15f, 0.2f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.3f, 0.0f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.3f, 0.0f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.6f, -0.6f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.6f, -0.6f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);

        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.5f, -0.45f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.5f, -0.45f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);

        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {-0.4f, -0.6f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {0.4f, -0.6f}));
        dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);

    }
};

#endif
