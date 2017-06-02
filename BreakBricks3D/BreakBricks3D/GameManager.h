#pragma once

class GameManager
{
public:
	// Singleton is accessed via getInstance()
	static GameManager& getInstance()
	{
		// lazy singleton, instantiated on first use
		static GameManager instance;
		return instance;
	}

	void init();
	void inputProcess();
	void renderGameObjects();

private:
	GameManager(void) // private constructor necessary to allow only 1 instance
	{
	}

	GameManager(GameManager const&); // prevent copies
	void operator=(GameManager const&); // prevent assignments

	static const int MAP_WIDTH = 5, MAP_HEIGHT = 5;

	// ������ ���۵Ǿ����� üũ
	bool isGameStarted = false;

	// �÷��̾ �ʱ�ȭ -> �Ƹ� �� �̰���
	void initPlayer();
	// ȭ�鿡 ������ �ʱ�ȭ
	void initMap();
};
