#include "../Game.h"

PowerUp::PowerUp(Game* g) : GoodObject(g) {
	texture = nullptr;
	GoodObject::onEnter();
}

PowerUp::~PowerUp() { GoodObject::onDelete(); }

void PowerUp::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth() > getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(powerUpTexture));
	}
}

void PowerUp::update() {
	if (SDL_HasIntersection(&getCollider(), &game->getCarColl())) {
		game->gotPower();
		alive = false;
	}
}