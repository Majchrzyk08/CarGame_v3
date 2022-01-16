#ifndef CARGAME_BLASTCOMMAND_H
#define CARGAME_BLASTCOMMAND_H

#include "Command.h"

class BlastCommand : public Command {
private:
    int x;
    int y;
    const int BLAST_SIZE = 300;

public:
    const string INFO_STRING = "[Mouse-click] to BLAST";

    BlastCommand() {
        info_string = INFO_STRING;
    };
    ~BlastCommand() = default;
    bool parse(SDL_Event& event) override;
    void execute() override;
};


#endif //CARGAME_BLASTCOMMAND_H
