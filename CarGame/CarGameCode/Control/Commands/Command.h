/* PASOS PARA CREAR NEW COMMAND
Kroki, by stworzyc nowa komende:
-include w commands.h
-dodac komende do commandFactory viewController
*/


#ifndef CARGAME_COMMAND_H
#define CARGAME_COMMAND_H

#include "../../Logic/Game.h"

class Command {
protected:
    string info_string;
    Game *game;
public:

    Command(){};
    virtual ~Command()=default;
    virtual bool parse(SDL_Event &event)=0;
    virtual void execute()=0;
    void bind(Game *game){
        this->game = game;
        game->appendHelpInfo(info_string);
    }
};


#endif //CARGAME_COMMAND_H
