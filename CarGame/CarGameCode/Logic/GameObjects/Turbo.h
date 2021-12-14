#pragma once
#include "GoodObject.h"

class Turbo : public GoodObject {

public:
	Turbo(Game* g);
	~Turbo();

	void draw();
	bool receiveCarCollision(Car* c);
};