#include "ShootCommand.h"

bool ShootCommand::parse(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s)return true;
	return false;
}

void ShootCommand::execute() {
	if (game->buy(cost)) {
		game->addObject(new b);
	}
}