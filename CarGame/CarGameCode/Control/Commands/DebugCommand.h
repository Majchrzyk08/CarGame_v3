#pragma once
#include "Command.h"

class DebugCommand :public Command {
    
public:
    const string INFO_STRING = "";

    DebugCommand() {
        info_string = INFO_STRING;
    };
    ~DebugCommand() = default;
    bool parse(SDL_Event& event) override;
    void execute() override;
};