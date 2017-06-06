#pragma once
#include "inc\fmod.h"

class SoundManager
{
public:
	// Singleton is accessed via getInstance()
	static SoundManager& getInstance()
	{
		// lazy singleton, instantiated on first use
		static SoundManager instance;
		return instance;
	}

	void init();
	void release();

	// ������� ���
	void playBackgroundMusic();
	// �� �ı��� ���� ȿ���� ���
	void playBrickSound();

private:
	SoundManager(void) // private constructor necessary to allow only 1 instance
	{
	}

	SoundManager(SoundManager const&); // prevent copies
	void operator=(SoundManager const&); // prevent assignments

	// fmod library for sound effects

	FMOD_SYSTEM *g_System;		// ���� �� �Ҹ� ���
	FMOD_SOUND *g_Sound[6];		// �������(ȿ����)�� ����
	FMOD_CHANNEL *g_Channel[2]; // ��������� ����
};