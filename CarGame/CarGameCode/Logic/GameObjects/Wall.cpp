#include "../Game.h"

Wall::Wall(Game* g) : GameObject(g) {
	texture = nullptr;
}

Wall::~Wall() {}

void Wall::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth()> getX()) { //calculo para saber cuando se tiene que empezar a dibujar dibujar
		drawTexture(game->getTexture(rockTexture));
	}
}

void Wall::update() {
	if (SDL_HasIntersection(&getCollider(), &game->getCarColl())) {
		game->gotHit(this);
		alive = false;
	}
	if (getX() < -game->getOrigin().getX() - getWidth())alive = false;
}