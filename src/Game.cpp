#include "../include/Game.h"
#include <iostream>

void Game::update(BaseEntity* test, OpenGLWidget w) {
    static float a = 0.0f;
    a += 0.01f;
    test->setPos({a, a});
    w.paintGL();
}
