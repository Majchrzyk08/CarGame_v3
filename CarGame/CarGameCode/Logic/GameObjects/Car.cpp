//
// Created by eys on 21/8/21.
//

#include "Car.h"
#include "../Game.h"

Car::Car(Game *game) : GameObject(game){
    texture = nullptr;
}

void Car::update() {
    int vspeedaux = 0;
    switch (vmove)
    {
    case 0:
        break;
    case -1:
        vspeedaux = -VSPEED;
        if (getY() - VSPEED - (getHeight() / 2) <= 0) {
            vspeedaux = 0;
            vmove = 0;
        }
        break;
    case 1:
        vspeedaux = VSPEED;
        if (getY() + VSPEED + (getHeight() / 2) >= game->getWindowHeight()) {
            vspeedaux = 0;
            vmove = 0;
        }
        break;
    }

    switch (hmove)
    {
    case 0:
        break;
    case 1:
        vel_ *= ACCELERATION;
        if (vel_ > MAX_SPEED) {
            vel_ = MAX_SPEED;
            hmove = 0;
        }
        else if (vel_ == 0) {
            vel_ = 1;
            hmove = 0;
        }
        break;
    case -1:
        vel_ *= DECELERATION;
        if (vel_ < 1) {
            vel_ = 1;
            hmove = 0;
        }
        break;
    }

    setPosition(getX() + vel_, getY() + vspeedaux);

    vector<Collider*> collisions = game->getCollisions(this);
    for (Collider* c : collisions)c->receiveCarCollision(this);
}

Car::~Car(){};

void Car::draw() {
    drawTexture(game->getTexture(carTexture));
}

void Car::gotHit() {
    if (power_ - 1 == 0) {
        game->vic(false);
        game->changeState(GAMEOVER);
    }
    else power_--;
    vel_=0;
}
void Car::gotPower() {
    if (power_ + 1 <= INITIAL_POWER)power_ += 1;
}

void Car::upNdown(int i) {
    vmove = i;
}

void Car::accelerateNdecelerate(int i) {
    hmove = i;
}

SDL_Rect Car::getCenter() {
    return { getX() + game->getOrigin().getX() - ((getWidth() / 10) / 2),getY() - ((getWidth() / 10) / 2),
           getWidth() / 10,getWidth() / 10
    };
}