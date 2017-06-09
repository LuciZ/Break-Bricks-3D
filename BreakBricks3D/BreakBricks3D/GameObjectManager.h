#pragma once
#include "GameObject.h"
#include "ParticleSystem.h"
#include "Ball.h"
#include <vector>
#include <deque>

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
	void initWalls();
	GameObject& getPlayer();
	// ���� ���� -> ���� ���� ������.
	void startBall();
	//void addGameObject(const GameObject& gameObject);
	void addBlock(const int x, const int y, const int matType = 0);
	GameObject* getBlock(const int x, const int y, const int MAP_WIDTH);
	void renderAll();

private:
	GameObjectManager(void) // private constructor necessary to allow only 1 instance
	{
	}

	GameObjectManager(GameObjectManager const&); // prevent copies
	void operator=(GameObjectManager const&); // prevent assignments

	static const float BALL_RADIUS;
	static const float LEFT_WALL_POS, RIGHT_WALL_POS, UP_WALL_POS, WALL_WIDTH;
	float ballSpeed;

	// ���� �ǰ� ����� �μ� ��
	GameObject player;
	Ball ball;

	// ���� ���� ����
	GameObject leftWall, rightWall, upWall;
	std::vector<GameObject*> blocks;

	// ��ƼŬ
	std::deque<ParticleSystem*> particleSystems;

	// �浹 üũ
	void collisionCheck();
	// ���� ���� �ε���
	void collisionBlock(GameObject* block, const Vector3D<float>& collisionPos);
};