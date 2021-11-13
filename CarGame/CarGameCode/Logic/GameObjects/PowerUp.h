#pragma once
#include "GoodObject.h"

class PowerUp : public GoodObject {
public:
	PowerUp(Game* g);
	~PowerUp();

	void draw();

	bool receiveCarCollision(Car* c);
};