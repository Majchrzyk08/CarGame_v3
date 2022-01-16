#include "../Game.h"


Turbo::Turbo(Game* g) : GoodObject(g) {
	this->setDimension(TURBO_WIDTH, TURBO_HEIGHT);
}

Turbo::~Turbo() {}

void Turbo::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth() > getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(turboTexture));
	}
}

bool Turbo::receiveCarCollision(Car* c) {
	c->gotTurbo();
	return true;
}