#include "../GameObjects/Bullet.h"
#include <vector>
#include "../Game.h"

Bullet::Bullet(Game* g) : GameObject(g) {
    this->setDimension(BULLET_WIDTH, BULLET_HEIGHT);
    this->onEnter();
    alive = true;
}

Bullet::~Bullet()
{
    this->onDelete();
}

void Bullet::draw()
{
    drawTexture(game->getTexture(bulletTexture));
}

void Bullet::update()
{
    if((counter + SPEED) < LIFE_LENGTH){
    setPosition(getX() + SPEED, getY());
    counter += SPEED;
    vector<Collider*> collisions = game->getCollisions(this); 
    for (Collider* c : collisions)c->receiveBulletCollision(this); 
    }
    else {
        if (counter < LIFE_LENGTH) {
            int x = LIFE_LENGTH - counter;
            setPosition(getX() + x, getY());
        }
        alive = false;
    }

}

void Bullet::gotHit() {
    alive = false;
}

bool Bullet::toDelete() {
    return !alive;
}


