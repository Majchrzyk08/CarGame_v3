#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"

class GameObjectGenerator {
    Point2D<int> static generateRandomPosition(Game *game, GameObject *o);
    void static addInRandomPosition(Game *game, GameObject *o);

public:
    static void generate(Game *game, int N_ROCKS = 0, int N_HEARTS = 0, int N_COINS = 0, int N_TURBOS = 0, int N_SUPER_ROCKS = 0){
        for(int i = 0; i < N_ROCKS; i++)
            addInRandomPosition(game, new Wall(game));
        for (int i = 0; i < N_HEARTS; i++)
            addInRandomPosition(game, new PowerUp(game));
        for (int i = 0; i < N_COINS; i++)
            addInRandomPosition(game, new Coin(game));
        for (int i = 0; i < N_TURBOS; i++)
            addInRandomPosition(game, new Turbo(game));
        for (int i = 0; i < N_SUPER_ROCKS; i++)
            addInRandomPosition(game, new SuperRock(game));
    }   
};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
