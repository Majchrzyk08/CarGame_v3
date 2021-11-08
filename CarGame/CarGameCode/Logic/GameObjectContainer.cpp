#include "GameObjectContainer.h"
#include "GameObjects/GameObject.h"

GameObjectContainer::~GameObjectContainer() {
	while (gameObjects.size()>0) {
		delete gameObjects[0];
		gameObjects[0] = nullptr;
		gameObjects.erase(gameObjects.begin());
	}
}

void GameObjectContainer::update() {
	for (GameObject* go : gameObjects)go->update();
}

void GameObjectContainer::draw() {
	for (GameObject* go : gameObjects)go->draw();
}

void GameObjectContainer::drawDebug() {
	for (GameObject* go : gameObjects)go->drawDebug();
}

void GameObjectContainer::add(GameObject* g) {
	gameObjects.push_back(g);
}

void GameObjectContainer::removeDead() {
	int i = 0;
	while (i < gameObjects.size()) {
		/*
		if (!gameObjects[i]->getAlive()) {
			delete gameObjects[i];
			gameObjects[i] = nullptr;
			gameObjects.erase(gameObjects.begin() + i);
		}*/
		if (hasCollision(gameObjects[i]) && gameObjects[i]->toDelete()) {
			delete gameObjects[i];
			gameObjects[i] = nullptr;
			gameObjects.erase(gameObjects.begin() + i);
		}
		else i++;
	}
}

bool GameObjectContainer::hasCollision(GameObject* g) {
	return getCollisions(g).size() > 0;
}

vector<Collider*> GameObjectContainer::getCollisions(GameObject* g) {
	vector<Collider*>aux;
	for (GameObject* go : gameObjects) if (go!=g && SDL_HasIntersection(&g->getCollider(), &go->getCollider())) aux.push_back(go);
	return aux;
}