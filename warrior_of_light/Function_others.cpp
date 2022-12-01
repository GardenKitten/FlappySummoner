#include "game.h"

extern struct wof summon_data;
extern struct Pillar pillar[4];

void Clean(void)//清空缓冲区
{
	char ch;
	while ((ch = getchar()) == ' ');
	/*while (_kbhit())
	{
		_getch();
	}*/
}

int Hit(void)
{
	if (summon_data.y <= -50 || summon_data.y >= 714)//撞到上下边界
	{
		return 1;
	}
	
	for (int i = 0; i < 4; i++) //撞到柱子
	{
		if (pillar[i].x > (200 - 149 +20) && pillar[i].x < (200 + 90 -20))
		{
			if (summon_data.y < (pillar[i].h - 45))
				return 1;

			else if (summon_data.y > (pillar[i].h + 15 + 264))
				return 1;

		}
	}
	

	return 0;
}

DWORD WINAPI GameStartSound(LPVOID lpParamer)//开始时音效
{
	mciSendString("open startsound.mp3", 0, 0, 0);
	mciSendString("play startsound.mp3", 0, 0, 0);
	mciSendString("close startsound.mp3", 0, 0, 0);
	return 0;
}

void PlaySound(void)
{
	//CreateThread(NULL, NULL, GameStartSound, NULL, NULL, NULL);
	//GameStartSound;
	char ch;
	mciSendString("open bgm.mp3", 0, 0, 0);
	mciSendString("play bgm.mp3 repeat", 0, 0, 0);
	mciSendString("open startsound.mp3", 0, 0, 0);
	mciSendString("play startsound.mp3 wait", 0, 0, 0);
	mciSendString("close startsound.mp3", 0, 0, 0);
	
}
