#pragma once
#include "BadObject.h"

class Wall : public BadObject{
public:
    Wall(Game* g);
    ~Wall();

    void draw();

    bool receiveCarCollision(Car* c);
    bool receiveBulletCollision(Bullet* b);
};