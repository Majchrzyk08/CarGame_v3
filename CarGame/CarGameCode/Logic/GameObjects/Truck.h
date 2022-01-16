#pragma once
#include "BadObject.h"

static int TRUCK_WIDTH = 120;
static int TRUCK_HEIGHT = 60;
static int TRUCK_VELOCITY = 5;

class Truck : public BadObject {

public:
    Truck(Game* g);
    ~Truck();

    void draw();
    void update();

    bool receiveCarCollision(Car* c);
    bool receiveBulletCollision(Bullet* b);
};