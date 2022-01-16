#include "../Game.h"
#include "Bullet.h"

Truck::Truck(Game* g) : BadObject(g) {
	this->setDimension(TRUCK_WIDTH, TRUCK_HEIGHT);
}

Truck::~Truck() {}

void Truck::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth() > getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(truckTexture));
	}
}

void Truck::update()
{
	setPosition(getX() - TRUCK_VELOCITY, getY());
}

bool Truck::receiveCarCollision(Car* c) {
	c->gotHit(1);
	alive = false;
	return true;
}

bool Truck::receiveBulletCollision(Bullet* b) {
	b->gotHit();
	alive = false;
	return true;
}