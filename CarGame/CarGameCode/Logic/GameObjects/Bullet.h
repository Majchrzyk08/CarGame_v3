#pragma once
#include "GameObject.h"

class Bullet : public GameObject {

public:
	Bullet(Game* g);
	~Bullet();

	void draw();
	void update() override {};


};