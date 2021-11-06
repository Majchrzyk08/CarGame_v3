#include "../Game.h"

Meta::Meta(Game* g) : GameObject(g) {
	texture = nullptr;
}

Meta::~Meta() {}

void Meta::draw() {
	if ((-game->getOrigin().getX()) + game->getWindowWidth() + getWidth() > getX()) { //calculo para saber cuando se tiene que empezar a dibujar
		drawTexture(game->getTexture(goalTexture));
	}	
}

void Meta::update() {
	if (SDL_HasIntersection(&getCollider(), &game->getCarColl())) {
		game->vic(true);
		game->changeState(GAMEOVER);
	}
}