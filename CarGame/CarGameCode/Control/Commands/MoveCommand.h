#pragma once
#include "Command.h"

class MoveCommand :public Command {
    int vel;
public:
    const string INFO_STRING = "[UP/DOWN] to move";

    MoveCommand() {
        info_string = INFO_STRING;
    };
    ~MoveCommand() = default;
    bool parse(SDL_Event & event) override;
    void execute() override;
};