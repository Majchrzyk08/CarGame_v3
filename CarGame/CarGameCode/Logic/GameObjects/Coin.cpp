#include "../Game.h"

Coin::Coin(Game* g) : GoodObject(g) {
	this->setDimension(COIN_WIDTH, COIN_HEIGHT);
	texture = nullptr;
	GoodObject::onEnter();
}

Coin::~Coin() { GoodObject::onDelete(); }

void Coin::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth() > getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(coinTexture));
	}
}

bool Coin::receiveCarCollision(Car* c) {
	c->gotCoin();
	alive = false;
	return true;
}