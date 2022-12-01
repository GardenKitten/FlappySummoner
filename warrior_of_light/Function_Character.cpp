#include "game.h"

IMAGE background;//
IMAGE background_start;
IMAGE background_die;
IMAGE die_background_1;
IMAGE summon[2];//��ʯ���ٻ�
IMAGE summon_fly[2];//�ٻ����
IMAGE summon_die;//�������
IMAGE gameover[2];//game over�Ի���
IMAGE up[2];//����
IMAGE down[2];//����
IMAGE menu[2];//�˵�

extern struct wof summon_data;
extern long int control;

void LoadResource(void)//������Դ
{
	loadimage(&background, "background.bmp", 1000, 714);
	loadimage(&background_start, "background_start.bmp", 1000, 714);
	loadimage(&background_die, "die.bmp", 1000, 714);
	loadimage(&die_background_1, "die_1.bmp", 1000, 714);
	loadimage(&summon[0], "1.bmp", 90, 105);
	loadimage(&summon[1], "1_1.bmp", 90, 105);
	loadimage(&summon_fly[0], "2.bmp", 90, 105);
	loadimage(&summon_fly[1], "2_1.bmp", 90, 105);
	loadimage(&summon_die, "2_2.bmp", 90, 105);
	loadimage(&gameover[0], "gameover.bmp", 800, 64);
	loadimage(&gameover[1], "gameover_1.bmp", 800, 64);
	loadimage(&up[0], "up.bmp", 149, 450);
	loadimage(&up[1], "up_1.bmp", 149, 450);
	loadimage(&down[0], "down.bmp", 149, 450);
	loadimage(&down[1], "down_1.bmp", 149, 450);
	loadimage(&menu[0], "menu.bmp", 400,361);
	loadimage(&menu[1], "menu_1.bmp", 400, 361);
}

DWORD WINAPI PlayMusic(LPVOID lpParamer)//��Ծʱ��������
{
	mciSendString("setaudio movie volume to 50",0,0,0);
	mciSendString("open jump.mp3", 0, 0, 0);
	mciSendString("play jump.mp3 wait", 0, 0, 0);
	mciSendString("close jump.mp3", 0, 0, 0);
	return 0;
}

DWORD WINAPI GameOverSound(LPVOID lpParamer)//ʧ��ʱ��Ч
{
	mciSendString("open gameoversound.mp3", 0, 0, 0);
	mciSendString("play gameoversound.mp3 wait", 0, 0, 0);
	mciSendString("close gameoversound.mp3", 0, 0, 0);
	return 0;
}



void PrintBackground(int i)//��ӡ����
{	
	if(i==0)
		putimage(0, 0, &background_start);
	else if(i==1)
		putimage(0, 0, &background);
	else if(i==2)
		putimage(0, 0, &background_die);

}

void PrintMenu(void)
{
	putimage(300, 50, &menu[1], SRCAND);//����ͼ
	putimage(300, 50, &menu[0], SRCPAINT);//����ͼ
}

void DrawSummon(int x, int y)//��ӡС��
{
	if (control % 2 == 0)//��ʯ��
	{
		putimage(x, y, &summon[1], SRCAND);//����ͼ
		putimage(x, y, &summon[0], SRCPAINT);//����ͼ		
	}
	else if (control % 2 == 1)//��¥��
	{
		putimage(x, y, &summon_fly[1], SRCAND);//����ͼ
		putimage(x, y, &summon_fly[0], SRCPAINT);//����ͼ

	}

}

void SummonMove(void)//С�������ƶ�&������Ծ��Ч
{
	char userkey = _getch();
	//Clean();
	if (userkey == ' ')
	{
		summon_data.y -= summon_data.speed;
		CreateThread(NULL, NULL, PlayMusic, NULL, NULL, NULL);
		PlayMusic;
		control += 1;
	}
	else
	{
		
	}
}


void PrintOver(void)//��Ϸ����
{
	mciSendString("close bgm.mp3", 0, 0, 0);
	int bmp = 1;

	while (summon_data.y < 810)
	{
		PrintBackground(1);
		for (int i = 0; i < 4; i++)//��ʾ����
		{
			PrintPillar(i);

		}
		if (bmp)
		{
			putimage(summon_data.x, summon_data.y, &summon_fly[1], SRCAND);//����ͼ
			putimage(summon_data.x, summon_data.y, &summon_fly[0], SRCPAINT);//����ͼ
			bmp--;
		}
		else
		{
			putimage(summon_data.x, summon_data.y, &summon_fly[1], SRCAND);//����ͼ
			putimage(summon_data.x, summon_data.y, &summon_die, SRCPAINT);//����ͼ
			bmp++;
		}

		summon_data.y += 10;
		
		Sleep(50);
	}
	putimage(0, 0, &background_die);
	Sleep(1000);

	CreateThread(NULL, NULL, GameOverSound, NULL, NULL, NULL);
	GameOverSound;
	/*mciSendString("open gameoversound.mp3", 0, 0, 0);
	mciSendString("play gameoversound.mp3", 0, 0, 0);*/

	int x = 100;
	int y = 714;
	while (y >= 70)
	{
		putimage(0, 0, &die_background_1);
		putimage(x, y, &gameover[1], SRCAND);//����ͼ
		putimage(x, y, &gameover[0], SRCPAINT);//����ͼ
		y -= 30;
		Sleep(50);
	}
	Sleep(9000);
	//mciSendString("close gameoversound.mp3", 0, 0, 0);
}
