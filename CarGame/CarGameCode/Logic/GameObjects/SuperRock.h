#pragma once
#include "BadObject.h"


static int SUPERROCK_WIDTH = 160;
static int SUPERROCK_HEIGHT = 80;

class SuperRock : public BadObject {
public:
    SuperRock(Game* g);
    ~SuperRock();

    void draw();

    bool receiveCarCollision(Car* c);
};