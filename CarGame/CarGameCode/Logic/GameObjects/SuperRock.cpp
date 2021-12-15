#include "../Game.h"

SuperRock::SuperRock(Game* g) : BadObject(g) {
	BadObject::onEnter();
	this->setDimension(SUPERROCK_WIDTH, SUPERROCK_HEIGHT);
}

SuperRock::~SuperRock() { BadObject::onDelete(); }

void SuperRock::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth() > getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(superRockTexture));
	}
}

bool SuperRock::receiveCarCollision(Car* c) {
	c->gotHit();
	c->gotHit();
	alive = false;
	return true;
}
