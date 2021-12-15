#pragma once
#include "BadObject.h"

static int WALL_WIDTH = 50;
static int WALL_HEIGHT = 50;

class Wall : public BadObject{

public:
    Wall(Game* g);
    ~Wall();

    void draw();

    bool receiveCarCollision(Car* c);
    bool receiveBulletCollision(Bullet* b);
};