#ifndef CARGAME_CHEATCOMMAND_H
#define CARGAME_CHEATCOMMAND_H

#include "Command.h"

class CheatCommand : public Command {
private:
    int id;

public:
    const string INFO_STRING = "[1-7] to spawn only this object";

    CheatCommand() {
        info_string = INFO_STRING;
    };
    ~CheatCommand() = default;
    bool parse(SDL_Event& event) override;
    void execute() override;
};


#endif //CARGAME_CHEATCOMMAND_H
