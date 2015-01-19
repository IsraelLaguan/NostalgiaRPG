#include "GameObject.h"

GameObject::GameObject()
{
	visibility = 100;
	action = false;
}


GameObject::~GameObject()
{
}


void GameObject::Draw()
{
	al_draw_bitmap(shape, x, y, 0);
}

void GameObject::SetDirection(int d)
{
	switch (d)
	{
	case DIR_RIGHT:
		direction = d;
		shape = shapeR;
		vx = movement;
		vy = 0;
		break;
	case DIR_LEFT:
		direction = d;
		shape = shapeL;
		vx = -1 * movement;
		vy = 0;
		break;
	case DIR_UP:
		direction = d;
		shape = shapeU;
		vx = 0;
		vy = -1 * movement;
		break;
	case DIR_DOWN:
		direction = d;
		shape = shapeD;
		vx = 0;
		vy = movement;
		break;
	case DIR_STOP:
		vx = vy = 0;
		break;
	}
}

