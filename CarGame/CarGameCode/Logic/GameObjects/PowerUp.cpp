#include "../Game.h"

PowerUp::PowerUp(Game* g) : GoodObject(g) {
	this->setDimension(POWERUP_WIDTH, POWERUP_HEIGHT);
}

PowerUp::~PowerUp() {}

void PowerUp::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth() > getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(powerUpTexture));
	}
}

bool PowerUp::receiveCarCollision(Car* c) {
	c->gotPower();
	alive = false;
	return true;
}