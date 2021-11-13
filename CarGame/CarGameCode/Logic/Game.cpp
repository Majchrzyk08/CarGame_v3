//
// Created by eys on 20/8/21.
//

#include "Game.h"

Game::Game(string name, int width, int height, int roadLength, int obstacles, int powerups) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    doExit = false;
    font = new Font("../Images/Monospace.ttf", 12);
    nObstacles_ = obstacles;
    nPowerups = powerups;
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
    GameObjectGenerator::generate(this, nObstacles_, nPowerups);
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
        time_ = (SDL_GetTicks()-timeOfStart) / 1000;
        distance_ = roadLength - car->getX();
        container->update();
        container->removeDead();
        break;
    case GAMEOVER:
        break;
    }
}

void Game::draw(){
    Infobar info(this);
    switch (currentState_)
    {
    case MENU:
    case GAMEOVER:
        info.drawState();
        info.drawHelp();
        break;
    case RUNNING:
        container->draw();
        if (debug_) container->drawDebug();
        info.drawInfo();
        info.drawHelp();
        break;
    }
}

void Game::appendHelpInfo(string s) {
    help.push_back(s);
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