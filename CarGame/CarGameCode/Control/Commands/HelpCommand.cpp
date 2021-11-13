#include "HelpCommand.h"

bool HelpCommand::parse(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_h)return true;
	return false;
}

void HelpCommand::execute() {
	game->switchHelp();
}