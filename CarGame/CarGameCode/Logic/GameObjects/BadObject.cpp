#include "BadObject.h"
#include "../Game.h"

void  BadObject::onEnter(){
    instances += 1;
};

void  BadObject::onDelete(){
    instances -= 1;
};

void BadObject::reset(){
    instances = 0;
};

bool BadObject::toDelete() {
    return !alive || game->isRebased(this);
}

bool BadObject::wave(int value = 150) {
    this->setPosition(getX() + value, getY());
    return true;
}

bool BadObject::blast(int x, int y, SDL_Rect blastBox) {
    if (this->collide(blastBox))
        this->setDead();
        return true;
    return false;

}

int BadObject::instances = 0;