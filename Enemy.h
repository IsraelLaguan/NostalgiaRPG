#include <stdio.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_image.h>

#pragma once
#include "GameObject.h"

#define NUM_FRAMES 6

class Enemy :
	public GameObject
{
public:
	ALLEGRO_BITMAP* animR[NUM_FRAMES];
	ALLEGRO_BITMAP* animL[NUM_FRAMES];
	ALLEGRO_BITMAP* animU[NUM_FRAMES];
	ALLEGRO_BITMAP* animD[NUM_FRAMES];

	int direction;

	int currentFrame;
	void Advance();
	void Move();

	Enemy();
	~Enemy();
};

