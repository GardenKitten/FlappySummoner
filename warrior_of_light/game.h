#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include <sys/types.h>
#include <graphics.h>
#include <mmsystem.h>
#include <pthread.h>

#pragma comment(lib,"winmm.lib")

struct wof//定义小人
{
	int x;
	int y;
	int speed;
};

struct Pillar//定义柱子
{
	int x;
	int y;
	int h;//上面柱子的高度
};

struct Button//定义按钮
{
	int x;//左上
	int y;
	int xx;//右下
	int yy;
};

void LoadResource(void);
void PrintBackground(int i);
void PrintMenu(void);
void DrawSummon(int x, int y);
void SummonMove(void);
void PlaySound(void);
void PrintOver(void);
int Hit(void);
void Clean(void);
void InitPillar(int);
void PrintPillar(int);
int InButton(struct Button *p);
int ClickButton(struct Button* p, ExMessage m);

