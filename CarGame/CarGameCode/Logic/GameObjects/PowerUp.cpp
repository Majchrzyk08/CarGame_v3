#include "../Game.h"

PowerUp::PowerUp(Game* g) :GameObject(g) {
	texture = nullptr;
}

PowerUp::~PowerUp(){}

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
	if (getX() < -game->getOrigin().getX() - getWidth())alive = false;
}