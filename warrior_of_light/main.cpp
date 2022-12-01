#include "game.h"

struct wof summon_data = { 200,100,140 };//初始化
struct Pillar pillar[4];
long int control = 0;//
struct Button start = { 352,376,449,395 };
struct Button end = { 554,376,650,395 };
ExMessage m;


int main(void)
{
	char ch;
	srand((unsigned int)time(NULL));
	initgraph(1000, 714);//设置屏幕大小
	LoadResource();//加载图片
	
    loop:mciSendString("open menumusic.mp3", 0, 0, 0);
	mciSendString("play menumusic.mp3 repeat", 0, 0, 0);
	summon_data.x = 200;
	summon_data.y = 100;
	while (1)
	{
		PrintBackground(0);
		PrintMenu();
		m = getmessage();
		if (ClickButton(&start, m))
		{
			break;
		}

		if (ClickButton(&end, m))
		{
			exit(0);
		}
		//Sleep(50);
	}
	mciSendString("close menumusic.mp3", 0, 0, 0);

	PrintBackground(1);//打印背景	
	DrawSummon(summon_data.x, summon_data.y);//打印小人
	PlaySound();//播放bgm

	for (int i = 0; i < 4; i++)
	{
		InitPillar(i);//初始化柱子
	}

	

	while (1)
	{
		//cleardevice();	
		PrintBackground(1);
		DrawSummon(summon_data.x, summon_data.y);			
		summon_data.y += 15;//小人不断下落

		for (int i = 0; i < 4; i++)//柱子移动&重置柱子
		{
			pillar[i].x -= 10;			
			if (pillar[i].x < ( - 149))
			{
				pillar[i].x = (1200 - 149);
				pillar[i].h = rand() % (400 - 50 + 1) + 50;
			}
		}

		for (int i = 0; i < 4; i++)//显示柱子
		{
			PrintPillar(i);

		}

		if (_kbhit())//如果有输入，移动小人
		{
			SummonMove();
		}

		if (Hit())//如果撞到上下边界，游戏结束
		{			
			break;
		}
		Sleep(50);
	}

	PrintOver();//game over函数
	system("CLS");
	control = 0;
	fflush(stdin);
	goto loop;
	closegraph();
	return 0;
}