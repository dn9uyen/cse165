#include "../include/PlayerBall.h"

void PlayerBall::launch() {
    inCannon = false;
    QVector2D launchVec = (getPos() - QVector2D{0.0f, 1.1f}).normalized();
    setVel(launchVec * 0.005f);
}

void PlayerBall::doPhysics(std::vector<BaseEntity *> entities) {
    if (inCannon) {
        return;
    }

    // Gravity and x movement
    setVel({getVel().x(), getVel().y() + gravity * timeStep});
    // Kinematic formulas
    setPos({getPos().x() + getVel().x() * timeStep,
            getPos().y() + (getVel().y() * timeStep) + (timeStep * timeStep * gravity / 2)});

    // Check collisions
    // Add check for entity type
    for (BaseEntity *entity : entities) {
        QVector2D dist = getPos() - entity->getPos();
        float entityRadius = dynamic_cast<Ball *>(entity)->getRadius();
        // Check if balls overlapping for collision
        if (dist.length() <= getRadius() + entityRadius) {
            // Move ball so it's not inside another ball
            float overlap = getRadius() + entityRadius - dist.length();
            QVector2D pushBack = dist.normalized() * overlap / 2; // Get direction and amount to push back
            setPos(getPos() + pushBack);

            // Calculate post collision velocity
            QVector2D unitNormalVec = (getPos() - entity->getPos()).normalized();
            QVector2D unitTangentVec = {-unitNormalVec.y(), unitNormalVec.x()};
            float normalVel = QVector2D::dotProduct(unitNormalVec, getVel());
            float tangentVel = QVector2D::dotProduct(unitTangentVec, getVel());
            QVector2D finalVel = -normalVel * unitNormalVec + tangentVel * unitTangentVec;
            setVel(finalVel * restitution);

            dynamic_cast<Ball *>(entity)->setHit(true);
        }
    }

    // Check y bounce
    if (getPos().y() < -1.0f) {
        setVel({getVel().x(), getVel().y() * -restitution});
        setPos({getPos().x(), -1.0f});
    } else if (getPos().y() > 1.0f) {
        setVel({getVel().x(), getVel().y() * -restitution});
        setPos({getPos().x(), 1.0f});
    }

    // Check x bounce
    if (getPos().x() < -1.0f) {
        setPos({-1.0f, getPos().y()});
        setVel({getVel().x() * -restitution, getVel().y()});
    } else if (getPos().x() > 1.0f) {
        setPos({1.0f, getPos().y()});
        setVel({getVel().x() * -restitution, getVel().y()});
    }

    // Clamp velocity
    float maxVel = 0.005f;
    if (abs(getVel().x()) > maxVel) {
        setVel({getVel().x() > 0.0f ? maxVel : -maxVel, getVel().y()});
    }
    if (abs(getVel().y()) > maxVel) {
        setVel({getVel().x(), getVel().y() > 0.0f ? maxVel : -maxVel});
    }
    if (abs(getVel().x()) < 0.00001f) {
        setVel({0, getVel().y()});
    }
    if (abs(getVel().y()) < 0.00001f) {
        setVel({getVel().x(), 0});
    }
}

bool PlayerBall::getCannonStatus() { return inCannon; }

void PlayerBall::setCannonstatus(bool status) { inCannon = status; }
