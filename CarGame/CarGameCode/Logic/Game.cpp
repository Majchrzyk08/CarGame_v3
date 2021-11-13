//
// Created by eys on 20/8/21.
//

#include "Game.h"

Game::Game(string name, int width, int height, int roadLength, int obstacles) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    doExit = false;
    font = new Font("../Images/Monospace.ttf", 12);
    nObstacles_ = obstacles;
    record_ = 0;
}

void Game::startGame() {
    if (container != nullptr)delete container;
    container = new GameObjectContainer();
    time_ = 0;
    timeOfStart = SDL_GetTicks();
    goal_ = new Meta(this); goal_->setDimension(50, height); goal_->setPosition(roadLength, height / 2);
    container->add(goal_);
    car = new Car(this); car->setDimension(CAR_WIDTH, CAR_HEIGHT); car->setPosition(car->getWidth(), height/ 2.0);
    container->add(car);
    GameObjectGenerator::generate(this, nObstacles_, 5);
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;

    // puesto para que no deje basura
    delete font;
    delete textureContainer;
    delete container;
}

void Game::update(){
    switch (currentState_)
    {
    case MENU:
        break;
    case RUNNING:
        time_ = (SDL_GetTicks()-timeOfStart) / 1000; //funciona raro y sinceramente no se por que
        distance_ = roadLength - car->getX();
        container->update();
        container->removeDead();
        break;
    case GAMEOVER:
        break;
    }
}

void Game::draw(){
    switch (currentState_)
    {
    case MENU:
        drawMenu();
        break;
    case RUNNING:
        container->draw();
        if (debug_) container->drawDebug();
        drawInfo();
        break;
    case GAMEOVER:
        drawGameOver();
        break;
    }
}

void Game::appendHelpInfo(string s) {
    help.push_back(s);
}

// no se muy bien si estos metodos tienen que ser a la fuerza tan "en la cara" pero no se me ocurre una forma distinta de escribir la info en pantalla
void Game::drawInfo() { 
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;

    SDL_Rect rect = {0, 0, getWindowWidth(),
                     int(font->getSize() * 1.8)};
    Box(rect, BLACK).render(renderer);
    
    // cosas de aqui van a tener que ser variables independientes
    string s1 = "Pos: " + to_string(int(car->getX())) + " "
               + to_string(int(car->getY())) + "  " + 
        "Distance: " + to_string(distance_)+ "  " +
        "Speed: " + to_string((int) car->getVel()) + "  " + 
        "Power: " + to_string(car->getPower()) + "  " + 
        "Time: " + to_string((int)time_) + "  " + 
        "Obstacles: " + to_string(BadObject::instances);
    string s2 = "State: Playing"; // esto deberia pillar el nombre de la variable directamente?

    renderText(s1, x, y);
    renderText(s2, x, height - font->getSize());

    if (debug_) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); 
        SDL_RenderDrawLine(renderer, width / 2, 0, width / 2, height);
        SDL_RenderDrawLine(renderer, 0, height / 2, width, height / 2);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
    if (help_) {
        int yh = font->getSize()*2;
        int i = 0;
        for (auto s : help) {
            renderText(s, x, yh+font->getSize()*i);
            i++;
        }        
    }
}
void Game::drawMenu() {
    string s1 = "Welcome to Super Cars";
    string s2 = "Level: " + to_string(level_);
    string s3 = "Press space to start";
    string s4 = "Press [h] for help";

    string s5 = "State: Menu";

    int x = width / 2 - (s1.length()/2)*font->getSize();
    int y = height / 2 - font->getSize() * 2;
    
    renderText(s1, x, y);
    renderText(s2, x, y + font->getSize());
    renderText(s3, x, y + font->getSize()*2);
    renderText(s4, x, y + font->getSize()*3);

    renderText(s5, font->getSize()/2, height - font->getSize());

    if (help_) {
        int xh = font->getSize() / 2;
        int i = 0;
        for (auto s : help) {
            renderText(s, font->getSize() / 2, xh + font->getSize() * i);
            i++;
        }
    }
}
void Game::drawGameOver() {
    if (record_ == 0)record_ = time_;
    else if (time_ < record_)record_ = time_;

    string s1=" ";
    string s2=" ";
    string s3=" ";

    if (!victory_) {
        s1 = "Game Over!";
    }
    else {
        s1 = "Congratulations!";
        s2 = "User wins";
        s3 = "Time: " + to_string((int)time_) + " Record: " + to_string((int)record_);
    }

    string s5 = "State: GameOver";

    int x = width / 2 - (s1.length() / 2) * font->getSize();
    int y = height / 2 - font->getSize() * 2;

    renderText(s1, x, y);
    renderText(s2, x, y + font->getSize());
    renderText(s3, x, y + font->getSize() * 2);

    renderText(s5, font->getSize() / 2, height - font->getSize());

    if (help_) {
        int xh = font->getSize() / 2;
        int i = 0;
        for (auto s : help) {
            renderText(s, font->getSize() / 2, xh + font->getSize() * i);
            i++;
        }
    }
}

void Game::changeState(state_ s) {
    if (currentState_ != s) currentState_ = s;
}

void Game::setUserExit() {
    doExit = true;
}

bool Game::isUserExit() {
    return doExit;
}

int Game::getWindowWidth(){
    return width;
}

int Game::getWindowHeight() {
    return height;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::setRenderer(SDL_Renderer *_renderer) {
    renderer = _renderer;
}

void Game::loadTextures() {
    if(renderer == nullptr)
        throw string("Renderer is null");

    textureContainer = new TextureContainer(renderer);
}

void Game::renderText(string text, int x, int y, SDL_Color color){
    font->render(renderer, text.c_str(), x, y, color);
}

bool Game::doQuit() {
    return isUserExit();
}

Texture *Game::getTexture(TextureName name) {
    return textureContainer->getTexture(name);
}

Point2D<int> Game::getOrigin() {
    return {int(-(car->getX() - car->getWidth())), 0};
}

bool Game::isRebased(GameObject* go) {
    return go->getX() < -getOrigin().getX();
}

void Game::carUpNdown(int i) {
    if(car!=nullptr) car->upNdown(i);
}

void Game::carAccNdec(int i) {
    if(car!=nullptr) car->accelerateNdecelerate(i);
}

void Game::addObject(GameObject* go) {
    container->add(go);
}

bool Game::objectHasCollision(GameObject* go) {
    return container->getCollisions(go).size() > 0;
}