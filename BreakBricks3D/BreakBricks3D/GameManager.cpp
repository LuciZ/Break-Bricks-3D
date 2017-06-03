#include "GameManager.h"
#include "InputManager.h"
#include "GameObjectManager.h"

void GameManager::init()
{
	// �÷��̾�(��) �ʱ�ȭ
	GameObjectManager::getInstance().initPlayer();

	// �� �ʱ�ȭ
	GameObjectManager::getInstance().initWalls();

	// �� �ʱ�ȭ
	GameObjectManager::getInstance().initBall();

	// �� �ʱ�ȭ
	initMap();
}

void GameManager::inputProcess()
{
	if (InputManager::getInstance().getKeyPressed(GLFW_KEY_A))
	{
		GameObjectManager::getInstance().getPlayer().translate(glm::vec3(-0.1f, 0.0f, 0.0f));
	}
	else if (InputManager::getInstance().getKeyPressed(GLFW_KEY_D))
	{
		GameObjectManager::getInstance().getPlayer().translate(glm::vec3(0.1f, 0.0f, 0.0f));
	}

	// �����̽���
	if (InputManager::getInstance().getKeyPressed(GLFW_KEY_SPACE))
	{
		if (isGameStarted == false) 
		{
			GameObjectManager::getInstance().startBall();
			isGameStarted = true;
		}
		//GameObjectManager::getInstance().getBlock(1, 1, MAP_WIDTH)->setActive(false);
	}
}

void GameManager::renderGameObjects()
{
	GameObjectManager::getInstance().renderAll();
}

void GameManager::initMap()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			GameObjectManager::getInstance().addBlock(i, j);
		}
	}
}
