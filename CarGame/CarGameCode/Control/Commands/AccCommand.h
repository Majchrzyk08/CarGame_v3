#pragma once
#include "Command.h"

class AccCommand :public Command {
    int vel;
public:
    const string INFO_STRING = "";

    AccCommand() {
        info_string = INFO_STRING;
    };
    ~AccCommand() = default;
    bool parse(SDL_Event& event) override;
    void execute() override;
};