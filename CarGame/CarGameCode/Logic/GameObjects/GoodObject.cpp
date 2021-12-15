#include "GoodObject.h"
#include "../Game.h"

void  GoodObject::onEnter() {
    instances += 1;
};

void  GoodObject::onDelete() {
    instances -= 1;
};

void GoodObject::reset() {
    instances = 0;
};

bool GoodObject::toDelete() {
    return !alive || game->isRebased(this);
}

bool GoodObject::wave(int value = 150) {
    this->setPosition(getX() - value, getY());
    return true;
}

int GoodObject::instances = 0;