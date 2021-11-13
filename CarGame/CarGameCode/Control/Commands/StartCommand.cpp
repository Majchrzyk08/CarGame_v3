#include "StartCommand.h"

bool StartCommand::parse(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)return true;
	return false;
}

void StartCommand::execute() {
	game->startGame();
	game->changeState(RUNNING);
}