#pragma once
#include "GameObject.h"
#include "ParticleSystem.h"
#include "Ball.h"
#include "Block.h"
#include "Item.h"
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

	static const float PLAYER_WIDTH, PLAYER_HEIGHT;
	static const float BALL_RADIUS;
	static const float LEFT_WALL_POS, RIGHT_WALL_POS, UP_WALL_POS, WALL_WIDTH;

	void loadPlayer();
	void loadBall();
	void initPlayer();
	void initBall();
	void initWalls();
	GameObject& getPlayer();
	// ���� ���� -> ���� ���� ������.
	void startBall();
	//void addGameObject(const GameObject& gameObject);
	void addBlock(const int x, const int y, const int matType, const int hp);
	Block* getBlock(const int x, const int y, const int MAP_WIDTH);
	void renderAll();
	void deleteAllObjects(bool allClear = false);
	// ���� Ŭ�������� (��� ���� �ı�) or ���� ���� (���� ������ ��)
	bool isGameClear();
	bool isGameOver();

private:
	GameObjectManager(void) // private constructor necessary to allow only 1 instance
	{
	}

	GameObjectManager(GameObjectManager const&); // prevent copies
	void operator=(GameObjectManager const&); // prevent assignments

	float ballSpeed;

	// ���� �ǰ� ����� �μ� ��
	GameObject player;
	Ball ball;

	// ���� ���� ����
	GameObject leftWall, rightWall, upWall;
	std::vector<Block*> blocks;

	// ��ƼŬ
	std::deque<ParticleSystem*> particleSystems;

	// ������
	std::deque<Item*> items;

	// �浹 üũ
	void collisionCheck();
	// ���� ���� �ε���
	void collisionBlock(Block* block, const Vector3D<float>& collisionPos);
	// ������ ����
	void addItem(const const Vector3D<float>& collisionPos, const int itemType, const int matType);
};