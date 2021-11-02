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
	if(getX()+getWidth()< -game->getOrigin().getX())game->freeWall(this);	
	else {
		if (SDL_HasIntersection(&getCollider(), &game->getCarColl())) {
			game->gotHit(this);
		}
	}
}