#include "../Game.h"

Wall::Wall(Game* g) : BadObject(g) {
	texture = nullptr;
	BadObject::onEnter();
}

Wall::~Wall() { BadObject::onDelete(); }

void Wall::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth()> getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(rockTexture));
	}
}

bool Wall::receiveCarCollision(Car* c) {
	c->gotHit();
	alive = false;
	return true;
}