#include "game.h"

struct wof summon_data = { 200,100,140 };//��ʼ��
struct Pillar pillar[4];
long int control = 0;//
struct Button start = { 352,376,449,395 };
struct Button end = { 554,376,650,395 };
ExMessage m;


int main(void)
{
	char ch;
	srand((unsigned int)time(NULL));
	initgraph(1000, 714);//������Ļ��С
	LoadResource();//����ͼƬ
	
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

	PrintBackground(1);//��ӡ����	
	DrawSummon(summon_data.x, summon_data.y);//��ӡС��
	PlaySound();//����bgm

	for (int i = 0; i < 4; i++)
	{
		InitPillar(i);//��ʼ������
	}

	

	while (1)
	{
		//cleardevice();	
		PrintBackground(1);
		DrawSummon(summon_data.x, summon_data.y);			
		summon_data.y += 15;//С�˲�������

		for (int i = 0; i < 4; i++)//�����ƶ�&��������
		{
			pillar[i].x -= 10;			
			if (pillar[i].x < ( - 149))
			{
				pillar[i].x = (1200 - 149);
				pillar[i].h = rand() % (400 - 50 + 1) + 50;
			}
		}

		for (int i = 0; i < 4; i++)//��ʾ����
		{
			PrintPillar(i);

		}

		if (_kbhit())//��������룬�ƶ�С��
		{
			SummonMove();
		}

		if (Hit())//���ײ�����±߽磬��Ϸ����
		{			
			break;
		}
		Sleep(50);
	}

	PrintOver();//game over����
	system("CLS");
	control = 0;
	fflush(stdin);
	goto loop;
	closegraph();
	return 0;
}