#pragma once
#include "Command.h"

class WaveCommand :public Command {

public:
    const string INFO_STRING = "[w] wave";

    WaveCommand() {
        info_string = INFO_STRING;
    };
    ~WaveCommand() = default;
    bool parse(SDL_Event& event) override;
    void execute() override;
};