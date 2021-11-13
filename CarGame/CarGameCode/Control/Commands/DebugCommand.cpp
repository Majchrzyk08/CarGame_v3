#include "DebugCommand.h"

bool DebugCommand::parse(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d)return true;
	return false;
}

void DebugCommand::execute() {
	game->switchDebug();
}