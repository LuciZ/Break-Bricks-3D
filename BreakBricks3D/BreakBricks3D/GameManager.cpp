#include "GameManager.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "SoundManager.h"
#include "GameLevelManager.h"

void GameManager::init()
{
	// ���� ���� �ʱ�ȭ
	GameLevelManager::getInstance().init();

	// �÷��̾�(��) �ʱ�ȭ
	GameObjectManager::getInstance().loadPlayer();

	// �� �ʱ�ȭ
	GameObjectManager::getInstance().loadBall();

	// �� �ʱ�ȭ
	GameObjectManager::getInstance().initWalls();

	// ���� �ʱ�ȭ
	GameLevelManager::getInstance().initNewLevel();

	// sound manager �ʱ�ȭ
	SoundManager::getInstance().init();

	// ������� ���
	SoundManager::getInstance().playBackgroundMusic();
}

void GameManager::update()
{
	if (isGameOver)
	{
		return;
	}

	// ���� Ŭ���� Ȯ��
	if (GameObjectManager::getInstance().isGameClear())
	{
		SoundManager::getInstance().stopBackgroungMusic();
		SoundManager::getInstance().playSound(SoundManager::GAME_CLEAR);

		// �����ִ� ��, ��ƼŬ�� ����
		GameObjectManager::getInstance().deleteAllBlocksAndParticles();

		sleep(4000);

		// ���� ���� �ʱ�ȭ , ���� ���� ������ ���� ����
		if (GameLevelManager::getInstance().initNewLevel() == false)
		{
			isGameOver = true;
			return;
		}

		isGameStarted = false;

		// ������� ���
		SoundManager::getInstance().playBackgroundMusic();
	}

	// ���� �������� Ȯ��
	if (GameObjectManager::getInstance().isGameOver())
	{
		SoundManager::getInstance().stopBackgroungMusic();
		SoundManager::getInstance().playSound(SoundManager::GAME_OVER);

		sleep(3000);

		isGameOver = true;

		return;
	}

	inputProcess();

	renderGameObjects();
}

void GameManager::release()
{
	// �����ִ� ��, ��ƼŬ�� ����
	GameObjectManager::getInstance().deleteAllBlocksAndParticles();
	// sound manager ����
	SoundManager::getInstance().release();
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

void GameManager::sleep(const int amount)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(amount));
}
