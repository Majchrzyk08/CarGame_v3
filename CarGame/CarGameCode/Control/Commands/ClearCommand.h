#ifndef CARGAME_CLEARCOMMAND_H
#define CARGAME_CLEARCOMMAND_H

#include "Command.h"

class ClearCommand : public Command {

public:
    const string INFO_STRING = "[0] to clear objects";

    ClearCommand() {
        info_string = INFO_STRING;
    };
    ~ClearCommand() = default;
    bool parse(SDL_Event& event) override;
    void execute() override;
};


#endif //CARGAME_CLEARCOMMAND_H
