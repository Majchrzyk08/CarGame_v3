//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H

#include <iostream>
#include <string>
#include <vector>

#include "../View/Infobar.h"
#include "../View/TextureContainer.h"
#include "../View/Texture.h"
#include "../View/Box.h"
#include "../View/Font.h"

#include "GameObjects/Car.h"
#include "GameObjects/Wall.h"
#include "GameObjects/PowerUp.h"
#include "GameObjects/Meta.h"

#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"

enum state_ {MENU, RUNNING, GAMEOVER};

using namespace std;

class Game{
    friend class Infobar;

private:
    string name;
    bool doExit;
    bool help_ = false;
    bool victory_ = false;
    bool debug_ = false;
    int roadLength;
    int width, height;
    Car *car = nullptr;
    int distance_;
    float time_;
    float timeOfStart;
    float record_;
    Meta* goal_ = nullptr;

    vector<string> help;

    GameObjectContainer* container = nullptr;

    int nObstacles_;
    int nPowerups;
    
    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;

    state_ currentState_ = MENU;

    int level_ = 0;

public:
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;
    
    const unsigned int WALL_WIDTH = 50;
    const unsigned int WALL_HEIGHT = 50;

    Game(string name, int width, int height, int roadLength, int obstacles, int powerups = 0);
    ~Game();

    void startGame();
    void update();
    void draw();

    void setUserExit();
    bool isUserExit();
    bool doQuit();

    int getWindowWidth();
    int getWindowHeight();

    Point2D<int> getOrigin();

    string getGameName();

    void setRenderer(SDL_Renderer *renderer);
    void loadTextures();
    Texture *getTexture(TextureName name);
    SDL_Renderer *getRenderer();
    void renderText(string text, int x, int y, SDL_Color color={0,0,0});

    void appendHelpInfo(string s);
    void clearHelp() { help.clear(); }
    void changeState(state_ s);
    void switchHelp() { help_ = !help_; }
    void switchDebug() { debug_ = !debug_; }
    void vic(bool i) { victory_ = i; }

    bool isRebased(GameObject* go);

    void carUpNdown(int i);
    void carAccNdec(int i);

    int getRoadlength() { return roadLength; }
    int getHeight() { return height; }

    void addObject(GameObject* go);
    bool objectHasCollision(GameObject* go);
    vector<Collider*> getCollisions(GameObject* go) { return container->getCollisions(go); }
};


#endif //CARGAME_GAME_H
