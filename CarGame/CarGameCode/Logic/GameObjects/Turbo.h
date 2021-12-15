#pragma once
#include "GoodObject.h"


static int TURBO_WIDTH = 80;
static int TURBO_HEIGHT = 40;

class Turbo : public GoodObject {

public:
	Turbo(Game* g);
	~Turbo();

	void draw();
	bool receiveCarCollision(Car* c);
};