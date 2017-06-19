#pragma once
#include "MovingGameObject.h"
#include "Ball.h"

class Item : public MovingGameObject
{
public:
	Item();
	~Item();

	static const int ITEM_SIZE = 3;
	static const int POWER_UP = 1, BALL_SIZE_DOWN = 2, PLAYER_SIZE_UP = 3;

	void initItem(Ball* ball, GameObject* player, const int itemType);
	void applyItem(bool apply = true);
	void render();

	bool isItemAvailable();

private:
	// ������ ���� �ð�
	static const int itemTime = 500;

	int itemType;
	// ������ ���� �ð�, �������Ҷ� ��� üũ��
	int itemTTL;

	Ball* ball;
	GameObject* player;
};