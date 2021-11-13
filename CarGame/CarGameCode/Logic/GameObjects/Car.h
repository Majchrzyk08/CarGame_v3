//
// Created by eys on 21/8/21.
//

#ifndef CARGAME_CAR_H
#define CARGAME_CAR_H


class Game;

#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

class Car : public GameObject{

private:

    const double ACCELERATION = 1.3;
    const double DECELERATION = 0.9;
    const int VSPEED = 5;
    const int MAX_SPEED = 10;
    const int INITIAL_POWER = 3;

    //variables para movimiento
    double vel_ = 0;
    int vmove = 0;
    int hmove = 0;
    //no se si es lo correcto pero como la otra es constante y no la puedo cambiar pues toca crear otra
    int power_ = INITIAL_POWER;

public:
    Car(Game *game);
    ~Car();

    virtual void draw();
    virtual void update();

    double getVel() { return vel_; }
    int getPower() { return power_; }

    void gotHit();
    void gotPower();

    virtual SDL_Rect getCenter();

    //para cambiar la posicion
    void upNdown(int i);
    void accelerateNdecelerate(int i);
};


#endif //CARGAME_CAR_H
