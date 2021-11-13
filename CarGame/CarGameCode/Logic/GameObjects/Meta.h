#pragma once
#include "../../Utils/Vector2D.h"
#include "../../View/Texture.h"
#include "../../View/Box.h"
#include "GameObject.h"

class Game;

class Meta : public GameObject{
public:
    Meta(Game* g);
    ~Meta();

    void draw();
    void update(){}

    bool receiveCarCollision(Car* c);
};