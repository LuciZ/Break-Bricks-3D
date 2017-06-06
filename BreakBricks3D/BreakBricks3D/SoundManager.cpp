#include "SoundManager.h"

void SoundManager::init()
{
	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 10, FMOD_INIT_NORMAL, nullptr);

	FMOD_System_CreateSound(g_System, "Audio\\bgm_lobby.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[0]); // Ÿ��Ʋ ȭ�� BGM
	FMOD_System_CreateSound(g_System, "Audio\\bgm_main.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[1]);  // ���� ȭ�� BGM
	FMOD_System_CreateSound(g_System, "Audio\\g_end.mp3", FMOD_DEFAULT, 0, &g_Sound[2]);         // ���ӿ��� ȿ����
	FMOD_System_CreateSound(g_System, "Audio\\g_jelly.mp3", FMOD_DEFAULT, 0, &g_Sound[3]);       // ���� �ٴڿ� ������ �� ȿ����
	FMOD_System_CreateSound(g_System, "Audio\\i_large_energy.mp3", FMOD_DEFAULT, 0, &g_Sound[4]);// ���� �ϼ����� �� ȿ����
	FMOD_System_CreateSound(g_System, "Audio\\r_levelup.mp3", FMOD_DEFAULT, 0, &g_Sound[5]);	  // ������ ���� �� ȿ����

	FMOD_System_Update(g_System);
}

void SoundManager::release()
{
	FMOD_Sound_Release(g_Sound[0]);
	FMOD_Sound_Release(g_Sound[1]);
	FMOD_Sound_Release(g_Sound[2]);
	FMOD_Sound_Release(g_Sound[3]);
	FMOD_Sound_Release(g_Sound[4]);
	FMOD_Sound_Release(g_Sound[5]);
	FMOD_System_Close(g_System);
	FMOD_System_Release(g_System);
}

void SoundManager::playBackgroundMusic()
{
	FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[0], 0, &g_Channel[0]); // Ÿ��Ʋ ȭ�� BGM ���
}

void SoundManager::playBrickSound()
{
	FMOD_System_PlaySound(g_System, FMOD_CHANNEL_FREE, g_Sound[4], 0, &g_Channel[1]); // ���� ���� ���� ���
}

