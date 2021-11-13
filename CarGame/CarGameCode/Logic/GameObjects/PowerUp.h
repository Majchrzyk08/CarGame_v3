#pragma once
#include "GameObject.h"

class PowerUp : public GameObject {
	bool alive = true;
public:
	PowerUp(Game* g);
	~PowerUp();

	void draw();
	void update();

	bool toDelete() { return !alive; }
};