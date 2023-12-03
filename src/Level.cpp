#include "../include/Level.h"
#include <QtCore/qdebug.h>
#include <QtCore/qtimer.h>
#include <__algorithm/remove_if.h>

void Level::update() {
    bucket.doMovement();
    // Ball in cannon logic
    if (playerBall.getCannonStatus()) {
        if (playerBallCount == 0) {
            playerBall.setPos({0.0f, 1.3f});
        } else {
            playerBall.setPos(cannon.getTip());
        }
    } else {
        playerBall.doPhysics(entities);
        if (playerBall.getPos().y() - playerBall.getRadius() <= -0.9f) {
            // Check if landed in bucket
            if (playerBall.getPos().x() < bucket.getPos().x() && playerBall.getPos().x() > bucket.getPos().x() - 0.6f) {
                playerBallCount++;
                playerBall.setCannonstatus(true);
                playerBall.setVel({0.0f, 0.0f});
            } else if (playerBall.getPos().y() == -1.0f) {
                playerBall.setCannonstatus(true);
                playerBall.setVel({0.0f, 0.0f});
            }
        }
    }

    for (BaseEntity *entity : entities) {
        Ball *ball = dynamic_cast<Ball *>(entity);
        if (ball->getHitStatus() == true && ball->getDeleteScheduled() == false) {
            ball->setDeleteScheduled(true);
            QTimer::singleShot(3000, [=] {
                if (ball->getMandatory() == true) {
                    score += 75;
                }
                score += 50;
                std::erase(entities, entity);
            });
        }
    }

    // Check if pass/fail level
    for (BaseEntity *entity : entities) {
        Ball *ball = dynamic_cast<Ball *>(entity);
        if (ball->getMandatory() == true) {
            if (playerBallCount == 0 && playerBall.getCannonStatus() == true) {
                status = -1;
            }
            return;
        }
    }
    status = 1;
}

void Level::draw() {
    cannon.draw();
    playerBall.draw();
    bucket.draw();
    for (BaseEntity *entity : entities) {
        entity->draw();
    }
};

void Level::processEvent(QEvent *event) {
    // Process input
    switch (((QKeyEvent *)event)->key()) {
    case Qt::Key_Right:
        cannon.rotate(true);
        break;
    case Qt::Key_Left:
        cannon.rotate(false);
        break;
    case Qt::Key_Down:
        if (playerBallCount == 0) {
            break;
        }
        if (playerBall.getCannonStatus()) {
            if (playerBallCount == 0) {
                break;
            }
            playerBall.launch();
            playerBallCount--;
        }
        break;
    }
}

int Level::getPlayerBallCount() { return playerBallCount; };

int Level::getScore() { return score; }

int Level::getStatus() { return status; }

void Level::setStatus(int s) { status = s; }
