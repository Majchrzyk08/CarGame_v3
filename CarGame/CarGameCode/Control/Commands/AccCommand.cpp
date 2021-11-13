#include "AccCommand.h"

bool AccCommand::parse(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
			vel = 1;
			return true;
		case SDLK_LEFT:
			vel = -1;
			return true;
		}
	}
	else if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
		case SDLK_LEFT:
			vel = 0;
			return true;
		}
	}
	return false;
}

void AccCommand::execute() {
	game->carAccNdec(vel);
}