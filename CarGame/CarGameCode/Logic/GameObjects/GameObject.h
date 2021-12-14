/*
STEPS CUANDO CREO NUEVO OBJETO:
Jak dodajemy obiekt to co trzeba zrobic:
-dodac do texture containera i zmienic liczbe tekstur
-stworzyc w gameObjectGenerator
-dac include w game.h
-zmienic konstruktor gry w game.h i game.cpp
-w startGame modyfikacja wywowalnia generare
-w Mainie zdefiniowac ile ma sie stworzyc
*/





#ifndef CARGAME_GAMEOBJECT_H
#define CARGAME_GAMEOBJECT_H

#include "Collider.h"
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"

class Game;

static int WALL_WIDTH = 50;
static int WALL_HEIGHT = 50;

static int POWERUP_WIDTH = 40;
static int POWERUP_HEIGHT = 40;

static int COIN_WIDTH = 20;
static int COIN_HEIGHT = 20;

static int BULLET_WIDTH = 20;
static int BULLET_HEIGHT = 5;

static int TURBO_WIDTH = 80;
static int TURBO_HEIGHT = 40;

static int SUPERROCK_WIDTH = 160;
static int SUPERROCK_HEIGHT = 80;

class GameObject : public Collider{

    Point2D<double> pos;
    int w, h;

protected:
    Game *game;
    Texture *texture;

    void drawTexture(Texture* texture);
public:

    GameObject(Game *game): game(game){};
    virtual ~GameObject(){};

    virtual void draw()=0;
    virtual void drawDebug();
    virtual void update()=0;

    virtual bool toDelete(){return false;}
    virtual void onEnter(){};
    virtual void onDelete(){};

    void setPosition(double x, double y);
    void setDimension(double width, double height);

    int getWidth() {return w;};
    int getHeight() {return h;};

    int getX() {return pos.getX();};
    int getY() {return pos.getY();};
    virtual SDL_Rect getCollider();
    virtual SDL_Rect getCenter();

    bool collide(SDL_Rect other);
};
#endif //CARGAME_GAMEOBJECT_H
