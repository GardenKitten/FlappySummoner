#include "game.h"

extern ExMessage m;

extern struct Button start;
extern struct Button end;

int InButton(struct Button *p)
{
	if (m.x > p->x && m.x < p->xx && m.y>p->y && m.y < p->yy)
	{
		return 1;
	}
	else
		return 0;
}

int ClickButton(struct Button *p, ExMessage m)
{
	if (InButton(p) && m.message == WM_LBUTTONDOWN)
	{
		return 1;
	}
	else
		return 0;
}