#include "../Game.h"

SuperRock::SuperRock(Game* g) : BadObject(g) {
	BadObject::onEnter();
	this->setDimension(SUPERROCK_WIDTH, SUPERROCK_HEIGHT);
}

SuperRock::~SuperRock() {  }

void SuperRock::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth() > getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(superRockTexture));
	}
}

bool SuperRock::receiveCarCollision(Car* c) {

    //# it's better to use a parameter goHit(HARM)
	c->gotHit(2);
	alive = false;
	return true;
}
