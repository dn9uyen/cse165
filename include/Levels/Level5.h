#ifndef LEVEL5_H
#define LEVEL5_H

#include "../BaseEntity.h"
#include "../Level.h"
#include "../PlayerBall.h"
#include <QtCore/qdebug.h>
#include <random>

class Level5 : public Level {
  public:
    Level5() {

        playerBallCount = 5;

        playerBall.setColor({0.65f, 0.65f, 0.65f});

        auto gen = std::default_random_engine(time(0));
        auto rand = std::uniform_real_distribution<float>(-0.9f, 0.9f);
        for (int i = 0; i < 20; i++) {
            // Non mandatory
            entities.push_back(new Ball(0.05, {0.1f, 0.5, 0.7f}, {rand(gen), rand(gen) / 1.5f}));
        }
        for (int i = 0; i < 10; i++) {
            // Non mandatory
            entities.push_back(new Ball(0.05, {1.0f, 0.5, 0.0f}, {rand(gen), rand(gen) / 1.5f}));
            dynamic_cast<Ball *>(entities.back())->setIsMandatory(true);
        }
    }
};

#endif
