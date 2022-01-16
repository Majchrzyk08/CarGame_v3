#ifndef CARGAME_GAMEOBJECTGENERATOR_H
#define CARGAME_GAMEOBJECTGENERATOR_H

#include "Game.h"

class GameObjectGenerator {
    Point2D<int> static generateRandomPosition(Game *game, GameObject *o);
    void static addInRandomPosition(Game *game, GameObject *o);
    void static addInFrontOfTheCar(Game* game, GameObject* go);

public:
    static void generate(Game *game, int N_ROCKS = 0, 
                                     int N_HEARTS = 0, 
                                     int N_COINS = 0, 
                                     int N_TURBOS = 0, 
                                     int N_SUPER_ROCKS = 0,
                                     int N_OILS = 0, 
                                     int N_TRUCKS = 0){
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
        for (int i = 0; i < N_OILS; i++)
            addInRandomPosition(game, new Oil(game));
        for (int i = 0; i < N_TRUCKS; i++)
            addInRandomPosition(game, new Truck(game));
    }   

    static void forceAddObject(Game* game, int id) {
        GameObject *o = nullptr;
        switch (id) {
        case 1:
            o = new Wall(game);
            break;
        case 2:
            o = new PowerUp(game);
            break;
        case 3:
            o = new Oil(game);
            break;
        case 4:
            o = new Truck(game);
            break;
        case 5:
            o = new SuperRock(game);
            break;
        case 6:
            o = new Turbo(game);
            break;
        case 7:
            o = new Coin(game);
            break;
            
        }
        if (o != nullptr) {
            addInFrontOfTheCar(game, o);
            
        }
    }

};


#endif //CARGAME_GAMEOBJECTGENERATOR_H
