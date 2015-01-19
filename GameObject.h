#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>

#pragma once


#define DIR_STOP  0
#define DIR_RIGHT 1
#define DIR_LEFT  2
#define DIR_UP    3
#define DIR_DOWN  4

class GameObject
{
public:
	ALLEGRO_BITMAP *shapeL;
	ALLEGRO_BITMAP *shapeR;
	ALLEGRO_BITMAP *shapeU;
	ALLEGRO_BITMAP *shapeD;
	ALLEGRO_BITMAP *shape;

	int x;
	int y;
	int vx;
	int vy;
	int speed;
	int visibility;
	int attack;
	int health;
	int defense;
	int movement;
	int direction;
	int width;
	int height;
	bool Xplane;
	bool action;

	GameObject();
	~GameObject();

	void Draw();
	void Move();
	void SetDirection(int d);
};

