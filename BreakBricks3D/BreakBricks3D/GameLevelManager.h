#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GameLevelManager
{
public:
	// Singleton is accessed via getInstance()
	static GameLevelManager& getInstance()
	{
		// lazy singleton, instantiated on first use
		static GameLevelManager instance;
		return instance;
	}

	void init();
	bool initNewLevel();

private:
	GameLevelManager(void) // private constructor necessary to allow only 1 instance
	{
	}

	GameLevelManager(GameLevelManager const&); // prevent copies
	void operator=(GameLevelManager const&); // prevent assignments

	// �� ���� ����, ������ �ʺ�� ����
	int totalLevel, mapWidth, mapHeight;
	int currentLevel = 0;
	// ������ ����
	vector<string> blockInfo;

	void initBlocks();
};