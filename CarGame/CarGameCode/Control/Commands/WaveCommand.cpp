#include "WaveCommand.h"

bool WaveCommand::parse(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_w)return true;
	return false;
}

void WaveCommand::execute() {
	if (game->buy(3)) {
		for each (GameObject* x in game->getGameObjects())
		{
			x->wave();
		}
		
		}
}