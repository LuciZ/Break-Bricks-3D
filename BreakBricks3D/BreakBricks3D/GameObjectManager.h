#pragma once
#include "GameObject.h"
#include "Ball.h"
#include <vector>

class GameObjectManager
{
public:
	// Singleton is accessed via getInstance()
	static GameObjectManager& getInstance()
	{
		// lazy singleton, instantiated on first use
		static GameObjectManager instance;
		return instance;
	}

	void initPlayer();
	void initBall();
	GameObject& getPlayer();
	// ���� ���� -> ���� ���� ������.
	void startBall();
	//void addGameObject(const GameObject& gameObject);
	void addBlock(const int x, const int y);
	GameObject* getBlock(const int x, const int y, const int MAP_WIDTH);
	void renderAll();

private:
	GameObjectManager(void) // private constructor necessary to allow only 1 instance
	{
	}

	GameObjectManager(GameObjectManager const&); // prevent copies
	void operator=(GameObjectManager const&); // prevent assignments

	static const float BALL_RADIUS;

	// ���� �ǰ� ����� �μ� ��
	GameObject player;
	Ball ball;
	std::vector<GameObject*> blocks;

	// �浹 üũ
	void collisionCheck();
};