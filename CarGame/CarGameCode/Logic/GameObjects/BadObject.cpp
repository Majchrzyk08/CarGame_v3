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
   // return !alive || game->isRebased(this);
    return true;
}

int BadObject::instances = 0;