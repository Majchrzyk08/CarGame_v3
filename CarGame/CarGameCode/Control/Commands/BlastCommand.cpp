#include "BlastCommand.h"

bool BlastCommand::parse(SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        Uint32 buttons;
        SDL_PumpEvents();  // make sure we have the latest mouse state.
        buttons = SDL_GetMouseState(&x, &y);
        return true;
    }
    return false;
}

void BlastCommand::execute() {
    if (game->buy(3)) {

        SDL_Rect blastBox = { x - BLAST_SIZE , y - BLAST_SIZE, BLAST_SIZE*2, BLAST_SIZE*2 };
        for (auto o : game->getGameObjects())
            o->blast(x, y, blastBox);
    }
}
