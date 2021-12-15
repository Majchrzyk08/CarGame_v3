#include "../Game.h"

Oil::Oil(Game* g) : BadObject(g) {
	this->setDimension(OIL_WIDTH, OIL_HEIGHT);
}

Oil::~Oil() { BadObject::onDelete(); }

void Oil::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth() > getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(oilTexture));
	}
}

bool Oil::receiveCarCollision(Car* c) {
	c->gotOil(); // multiply spped 0.7
	return true;
}
