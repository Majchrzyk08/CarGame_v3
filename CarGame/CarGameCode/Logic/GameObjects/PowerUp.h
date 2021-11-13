#pragma once
#include "GameObject.h"

class PowerUp : public GameObject {
public:
	PowerUp(Game* g);
	~PowerUp();

	void draw();
	void update();

};