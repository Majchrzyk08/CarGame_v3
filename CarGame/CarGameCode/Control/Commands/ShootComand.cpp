#include "ShootCommand.h"
#include "../../Logic/GameObjects/Bullet.h"

bool ShootCommand::parse(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s)return true;
	return false;
}

void ShootCommand::execute() {
	if (game->buy(1)) { 
		Bullet* bullet = new Bullet(game);
		bullet->setPosition(game->getXOfTheCar(), game->getYOfTheFrontOfTheCar());
		game->addObject(bullet);
	}
}