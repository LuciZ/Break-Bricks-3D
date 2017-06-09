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
	void update();
	void release();

private:
	GameManager(void) // private constructor necessary to allow only 1 instance
	{
	}

	GameManager(GameManager const&); // prevent copies
	void operator=(GameManager const&); // prevent assignments

	// ���� ���� ����
	int currentLevel = 0;
	// ������ ���۵Ǿ����� üũ
	bool isGameStarted = false;


	void inputProcess();
	void renderGameObjects();
};
