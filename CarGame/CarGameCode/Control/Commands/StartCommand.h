#pragma once
#include "Command.h"

class StartCommand :public Command {

public:
    const string INFO_STRING = "[ ] space to skip";

    StartCommand() {
        info_string = INFO_STRING;
    };
    ~StartCommand() = default;
    bool parse(SDL_Event& event) override;
    void execute() override;
};