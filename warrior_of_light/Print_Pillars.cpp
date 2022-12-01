#include "game.h"

extern struct Pillar pillar[4];
extern IMAGE up[2];//上面的柱子
extern IMAGE down[2];//下面的柱子

void InitPillar(int i)//初始化
{
	
		pillar[i].x = 1000 + i * 300;
		pillar[i].y = 0;
		pillar[i].h = rand() % (400 - 50 + 1) + 50;
	
}

void PrintPillar(int i)
{
	putimage(pillar[i].x, 0, 149, pillar[i].h, &up[1],0,450-pillar[i].h,SRCAND);//上面的柱子
	putimage(pillar[i].x, 0, 149, pillar[i].h, &up[0], 0, 450-pillar[i].h, SRCPAINT);

	putimage(pillar[i].x, pillar[i].h + 264, 149, 450-pillar[i].h, &down[1], 0, 0, SRCAND);//下面的柱子
	putimage(pillar[i].x, pillar[i].h + 264, 149, 450-pillar[i].h, &down[0], 0, 0, SRCPAINT);
}