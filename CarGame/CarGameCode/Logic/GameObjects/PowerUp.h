#pragma once
#include "GoodObject.h"


static int POWERUP_WIDTH = 40;
static int POWERUP_HEIGHT = 40;

class PowerUp : public GoodObject {
public:
	PowerUp(Game* g);
	~PowerUp();

	void draw();

	bool receiveCarCollision(Car* c);
};