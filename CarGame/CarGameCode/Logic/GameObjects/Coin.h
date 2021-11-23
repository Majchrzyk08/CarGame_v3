#pragma once
#include "GoodObject.h"

class Coin : public GoodObject {

public:
	Coin(Game* g);
	~Coin();

	void draw();

	bool receiveCarCollision(Car* c);
};