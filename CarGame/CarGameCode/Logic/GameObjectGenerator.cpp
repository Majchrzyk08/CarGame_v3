#include "GameObjectGenerator.h"

Point2D<int> GameObjectGenerator::generateRandomPosition(Game* game, GameObject* go) {
	return Point2D<int>(rand() % (game->getRoadlength() - (go->getWidth() * 2)) + (go->getWidth() * 2), rand() % (game->getHeight() + go->getHeight()) - go->getHeight());
}

void GameObjectGenerator::addInRandomPosition(Game* game, GameObject* go) {
	Point2D<int> pos = generateRandomPosition(game, go);
	go->setPosition(pos.getX(), pos.getY());
	go->setDimension(game->WALL_WIDTH, game->WALL_HEIGHT);
	if (!game->objectHasCollision(go)) game->addObject(go);
	else delete go;
}