#pragma once
#include "BadObject.h"

static int OIL_WIDTH = 40;
static int OIL_HEIGHT = 40;

class Oil : public BadObject {
public:
    Oil(Game* g);
    ~Oil();

    void draw();
    bool receiveCarCollision(Car* c);
};