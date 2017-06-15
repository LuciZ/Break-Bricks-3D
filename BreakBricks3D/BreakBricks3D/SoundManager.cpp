#include "SoundManager.h"

void SoundManager::init()
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, AUDIO_SIZE, FMOD_INIT_NORMAL, nullptr);

	// Ÿ��Ʋ ȭ�� BGM
	FMOD_System_CreateStream(g_System, "Audio\\bgm_lobby.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[0]);
	// ���� ȭ�� BGM
	FMOD_System_CreateStream(g_System, "Audio\\bgm_main.wav", FMOD_LOOP_NORMAL, 0, &g_Sound[1]);
	// ���ӿ��� ȿ����
	FMOD_System_CreateSound(g_System, "Audio\\jingle_negative_001.wav", FMOD_DEFAULT, 0, &g_Sound[GAME_OVER]);
	// ��Ͽ� �浹 ȿ����
	FMOD_System_CreateSound(g_System, "Audio\\atk_gun.wav", FMOD_DEFAULT, 0, &g_Sound[BLOCK_COLLISION]);
	// ��� ���� ȿ����
	FMOD_System_CreateSound(g_System, "Audio\\atk_missile.wav", FMOD_DEFAULT, 0, &g_Sound[BLOCK_DESTROY]);
	// Ŭ���� ���� �� ȿ����
	FMOD_System_CreateSound(g_System, "Audio\\jingle_positive_002.wav", FMOD_DEFAULT, 0, &g_Sound[GAME_CLEAR]);
	// ������ ���� �� ȿ����
	FMOD_System_CreateSound(g_System, "Audio\\ui_heart.wav", FMOD_DEFAULT, 0, &g_Sound[ITEM_APPLY]);
	

	FMOD_System_Update(g_System);
}

void SoundManager::release()
{
	for (int i = 0; i < AUDIO_SIZE; i++)
	{
		FMOD_Sound_Release(g_Sound[i]);
	}
	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

void SoundManager::playBackgroundMusic()
{
	FMOD_System_PlaySound(g_System, FMOD_CHANNEL_REUSE, g_Sound[1], 0, &g_Channel[0]);
}

void SoundManager::stopBackgroungMusic()
{
	FMOD_Channel_Stop(g_Channel[0]);
}

void SoundManager::playSound(const int soundType)
{
	FMOD_System_PlaySound(g_System, FMOD_CHANNEL_REUSE, g_Sound[soundType], 0, &g_Channel[1]);
}

