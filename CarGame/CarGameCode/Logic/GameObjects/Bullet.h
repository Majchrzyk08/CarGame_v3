#pragma once
#include "GameObject.h"

class Bullet : public GameObject {

private:
	const int SPEED = 15;
	const int LIFE_LENGTH = 700;
	int counter = 0;

protected:
	bool alive;

public:
	Bullet(Game* g);
	~Bullet();

	void gotHit();
	void draw() override;
	void update() override;
	bool toDelete() override;


};