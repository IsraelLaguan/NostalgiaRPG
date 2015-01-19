#include "Enemy.h"


Enemy::Enemy()
{

}


Enemy::~Enemy()
{
	for (int i = 0; i < NUM_FRAMES; i++)
	{
		al_destroy_bitmap(animR[i]);
		al_destroy_bitmap(animL[i]);
		al_destroy_bitmap(animU[i]);
		al_destroy_bitmap(animD[i]);
	}

}

void Enemy::Advance()
{
	int d = direction;
	currentFrame++;
	if (currentFrame == NUM_FRAMES)
		currentFrame = 0;
	switch (d)
	{
	case DIR_RIGHT:
		shape = animR[currentFrame];
		break;
	case DIR_LEFT:
		shape = animL[currentFrame];
		break;
	case DIR_UP:
		shape = animU[currentFrame];
		break;
	case DIR_DOWN:
		shape = animD[currentFrame];
		break;
	default:
		break;
	}
}

void Enemy::Move()
{
	if (action == true)
	{
		switch (direction)
		{
		case DIR_RIGHT:
			direction = DIR_DOWN;
			break;
		case DIR_LEFT:
			direction = DIR_UP;
			break;
		case DIR_UP:
			direction = DIR_RIGHT;
			break;
		case DIR_DOWN:
			direction = DIR_LEFT;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (direction)
		{
		case DIR_RIGHT:
			x += movement;
			break;
		case DIR_LEFT:
			x -= movement;
			break;
		case DIR_UP:
			y -= movement;
			break;
		case DIR_DOWN:
			y += movement;
			break;
		default:
			break;
		}
	}

	Advance();
}