#pragma once
#include "GoodObject.h"

static int COIN_WIDTH = 20;
static int COIN_HEIGHT = 20;

class Coin : public GoodObject {

public:
	Coin(Game* g);
	~Coin();

	void draw();

	bool receiveCarCollision(Car* c);
};