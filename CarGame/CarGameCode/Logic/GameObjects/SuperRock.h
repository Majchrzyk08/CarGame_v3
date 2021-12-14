#pragma once
#include "BadObject.h"

class SuperRock : public BadObject {
public:
    SuperRock(Game* g);
    ~SuperRock();

    void draw();

    bool receiveCarCollision(Car* c);
};