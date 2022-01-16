#include "../Game.h"
#include "Bullet.h"

Wall::Wall(Game* g) : BadObject(g) {
	this->setDimension(WALL_WIDTH, WALL_HEIGHT);
}

Wall::~Wall() {}

void Wall::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth()> getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(rockTexture));
	}
}

bool Wall::receiveCarCollision(Car* c) {
	c->gotHit(1);
	alive = false;
	return true;
}

bool Wall::receiveBulletCollision(Bullet* b) {
	b->gotHit();
	alive = false;
	return true;
}