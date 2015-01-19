#include "Physics.h"


Physics::Physics()
{
	
}


Physics::~Physics()
{
	al_destroy_bitmap(bw);
}

void  Physics::Move(GameObject* a, bool Xplane)
{
	if (Xplane)
	{
		int newx = a->x + a->vx;
		a->x = newx;
	}
	else
	{
		int newy = a->y + a->vy;
		a->y = newy;
	}
}

bool Physics::Collision(GameObject* o1, GameObject* o2)
{
	float x2 = (o1->x - o2->x)*(o1->x - o2->x);
	float y2 = (o1->y - o2->y)*(o1->y - o2->y);
	float d = sqrt(x2 + y2);

	if (d < COLL_DISTANCE)
		return true;
	else
		return false;
}

void Physics::Check(GameObject* a, int d)
{
	al_lock_bitmap(bw, al_get_bitmap_format(bw), ALLEGRO_LOCK_READONLY);
	
	ALLEGRO_COLOR c1;
	unsigned char r1, g1, b1;

	int xspot = a->x + (a->width / 2);
	int yspot = a->y + (a->height / 2);
			
	switch (d)
	{
		case DIR_RIGHT:
			c1 = al_get_pixel(bw, (xspot + a->width/2) + 5, yspot);
			al_unmap_rgb(c1, &r1, &g1, &b1);
			if (r1 == 0 && g1 == 0 && b1 == 0)
				a->action = true;
			else
				a->action = false;
			break;
		case DIR_LEFT:
			c1 = al_get_pixel(bw, (xspot - a->width/2) - 5, yspot);
			al_unmap_rgb(c1, &r1, &g1, &b1);
			if (r1 == 0 && g1 == 0 && b1 == 0)
				a->action = true;
			else
				a->action = false;
			break;
		case DIR_UP:
			c1 = al_get_pixel(bw, xspot, (yspot - a->height/2) - 5);
			al_unmap_rgb(c1, &r1, &g1, &b1);
			if (r1 == 0 && g1 == 0 && b1 == 0)
				a->action = true;
			else
				a->action = false;
			break;
		case DIR_DOWN:
			c1 = al_get_pixel(bw, xspot, (yspot + a->height/2) + 5);
			al_unmap_rgb(c1, &r1, &g1, &b1);
			if (r1 == 0 && g1 == 0 && b1 == 0)
				a->action = true;
			else
				a->action = false;
			break;
		default:
			break;
	}
		
	al_unlock_bitmap(bw);
}

void Physics::enemyCheck(GameObject* a, int* d)
{

	al_lock_bitmap(bw, al_get_bitmap_format(bw), ALLEGRO_LOCK_READONLY);

	ALLEGRO_COLOR c1;
	unsigned char r1, g1, b1;

	int xspot = a->x + (a->width / 2);
	int yspot = a->y + (a->height / 2);

	switch (*d)
	{
	case DIR_RIGHT:
		c1 = al_get_pixel(bw, (xspot + a->width / 2) + 5, yspot);
		al_unmap_rgb(c1, &r1, &g1, &b1);
		if (r1 == 0 && g1 == 0 && b1 == 0)
			a->action = true;
		else
			a->action = false;
		break;
	case DIR_LEFT:
		c1 = al_get_pixel(bw, (xspot - a->width / 2) - 5, yspot);
		al_unmap_rgb(c1, &r1, &g1, &b1);
		if (r1 == 0 && g1 == 0 && b1 == 0)
			a->action = true;
		else
			a->action = false;
		break;
	case DIR_UP:
		c1 = al_get_pixel(bw, xspot, (yspot - a->height / 2) - 5);
		al_unmap_rgb(c1, &r1, &g1, &b1);
		if (r1 == 0 && g1 == 0 && b1 == 0)
			a->action = true;
		else
			a->action = false;
		break;
	case DIR_DOWN:
		c1 = al_get_pixel(bw, xspot, (yspot + a->height / 2) + 5);
		al_unmap_rgb(c1, &r1, &g1, &b1);
		if (r1 == 0 && g1 == 0 && b1 == 0)
			a->action = true;
		else
			a->action = false;
		break;
	default:
		break;
	}

	
	al_unlock_bitmap(bw);
}
