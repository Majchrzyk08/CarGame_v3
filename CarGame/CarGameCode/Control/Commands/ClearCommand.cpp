#include "ClearCommand.h"

bool ClearCommand::parse(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        SDL_Keycode key = event.key.keysym.sym;
        if (key == SDLK_0)
            return true;
    }
    return false;
}

void ClearCommand::execute() {
    game->deleteAllObjects();
}
