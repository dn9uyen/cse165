#ifndef GAME_H
#define GAME_H

#include "BaseEntity.h"
#include "OpenGLWidget.h"
#include "Level.h"

class Game {
private:
    Level* currentLevel;

  public:
    Game();
    void run();
    void update(BaseEntity *test, OpenGLWidget w);
};

#endif
