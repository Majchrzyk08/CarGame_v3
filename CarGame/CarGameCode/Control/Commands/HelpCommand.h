#pragma once
#include "Command.h"

class HelpCommand :public Command {

public:
    const string INFO_STRING = "[h] toggle help";

    HelpCommand() {
        info_string = INFO_STRING;
    };
    ~HelpCommand() = default;
    bool parse(SDL_Event& event) override;
    void execute() override;
};