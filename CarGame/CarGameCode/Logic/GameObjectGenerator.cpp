#include "GameObjectGenerator.h"

Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* go) {
	int x = rand() % game->getRoadLength() + (go->getWidth() * 2);
	int y1 = game->getWindowHeight() - (go->getHeight()*2);
	int y = rand() % y1 + go->getHeight();
	return Point2D<int>(x, y);
}

void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* go) {
	Point2D<int> pos = generateRandomPosition(game, go);
	go->setPosition(pos.getX(), pos.getY());
	if (!game->objectHasCollision(go)) game->addObject(go);
	else delete go;
}