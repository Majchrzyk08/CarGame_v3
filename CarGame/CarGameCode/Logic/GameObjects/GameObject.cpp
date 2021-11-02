#include "GameObject.h"
#include "../Game.h"

void GameObject::setDimension(double width, double height) {
    w = width;
    h = height;
};

void  GameObject::setPosition(double x, double y) {
    pos = Point2D<double>(x, y);
};

void GameObject::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x , c.y + dY, c.w, c.h };
    texture->render(textureBox);
}

void GameObject::drawDebug() {
    Box(getCollider(), RED).render(game->getRenderer());
    Box(getCenter(), BLUE).render(game->getRenderer());
}

SDL_Rect GameObject::getCollider() {
    return { int(getX() - getWidth() + game->getOrigin().getX()),//mirar car.cpp para explicacion de por que el calculo esta cambiado
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
}

SDL_Rect GameObject::getCenter() {
    return { getX() + game->getOrigin().getX() - (getWidth() / 2) - ((getWidth()/10)/2),getY()-((getWidth()/10)/2),
        getWidth() / 10,getWidth() / 10
    };
}