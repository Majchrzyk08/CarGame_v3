#include "MoveCommand.h"

bool MoveCommand::parse(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			vel = -1;
			return true;
		case SDLK_DOWN:
			vel = 1;
			return true;
		}
	}
	else if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
		case SDLK_DOWN:
			vel = 0;
			return true;
		}
	}
	return false;
}

void MoveCommand::execute() {
	game->carUpNdown(vel);
}